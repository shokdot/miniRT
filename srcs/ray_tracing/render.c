/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/27 20:31:34 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void my_mlx_pixel_put(t_tracer_ptr tracer, int x, int y, int color)
{
	char	*dst;

	dst = tracer->img->img_data + (y * tracer->img->size_line + x
			* (tracer->img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	render(t_tracer_ptr tracer)
{
	init_img(tracer);
	init_vplane(tracer);

    int x, y;
    double ray_x, ray_y;
	t_ray_ptr ray;
	t_node_ptr node;

    // Camera coordinate system
    t_vec3 forward = *(tracer->scene->camera->norm); // (0, 0, 1)
    t_vec3 up_ref = (t_vec3){0, 1, 0};
    t_vec3 right = vec3_norm(vec3_cross(forward, up_ref));
    t_vec3 up = vec3_norm(vec3_cross(right, forward));
	t_vec3 ray_origin = *(tracer->scene->camera->cords); // (-50, 0, 20)

	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			my_mlx_pixel_put(tracer, j, i, 0xFFFFFF);
		}
	}

	node = tracer->scene->figures->head;
	while (node != NULL)
	{
		for (y = 0; y < HEIGHT; ++y)
		{
			for (x = 0; x < WIDTH; ++x)
			{
				ray_x = (x - WIDTH / 2.0) * tracer->scene->vplane->pixel_dx;
				ray_y = (HEIGHT / 2.0 - y) * tracer->scene->vplane->pixel_dy;

				t_vec3 ray_dir = vec3_norm((t_vec3){
					forward.x + ray_x * right.x + ray_y * up.x,
					forward.y + ray_x * right.y + ray_y * up.y,
					forward.z + ray_x * right.z + ray_y * up.z
				});

				ray = init_ray(ray_origin, ray_dir);
				double t = intersect_api(node, *ray);

				free(ray);  // Free the allocated ray
				int color = vec3_to_hex(get_color(node));
				if (t > 0)
					my_mlx_pixel_put(tracer, x, y, color);
			}
		}
	node = node->next;
	}
	mlx_put_image_to_window(tracer->mlx->mlx, tracer->mlx->mlx_win,
		tracer->img->img, 0, 0);
	return 123;
}