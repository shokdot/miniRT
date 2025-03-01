/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/01 13:46:39 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	my_mlx_pixel_put(t_tracer_ptr tracer, int x, int y, int color)
{
	char	*dst;

	dst = tracer->img->img_data + (y * tracer->img->size_line + x
			* (tracer->img->bpp / 8));
	*(unsigned int *)dst = color;
}
int	render(t_tracer_ptr tracer)
{
	t_vec3		up_ref;
	t_vec3		right;
	t_vec3		up;
	t_node_ptr	node;
	double		ray_x;
	double		ray_y;
	t_vec3		ray_dir;
	t_ray_ptr	ray;
	double		t;
	int			color;

	init_vplane(tracer);
	// Set up camera coordinate system
	t_vec3 forward = *(tracer->scene->camera->norm); // e.g. (0, 0, 1)
	up_ref = (t_vec3){0, 1, 0};
	right = vec3_norm(vec3_cross(forward, up_ref));
	up = vec3_norm(vec3_cross(right, forward));
	t_vec3 ray_origin = *(tracer->scene->camera->cords); // e.g. (-50, 0, 20)
	// Draw background white
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			my_mlx_pixel_put(tracer, j, i, 0xFFFFFF);
		}
	}
	// For each figure in the scene
	node = tracer->scene->figures->head;
	while (node != NULL)
	{
		for (int y = 0; y < HEIGHT; ++y)
		{
			for (int x = 0; x < WIDTH; ++x)
			{
				// Calculate ray direction for this pixel
				ray_x = (x - WIDTH / 2.0) * tracer->scene->vplane->pixel_dx;
				ray_y = (HEIGHT / 2.0 - y) * tracer->scene->vplane->pixel_dy;
				ray_dir = vec3_norm((t_vec3){forward.x + ray_x * right.x + ray_y
						* up.x, forward.y + ray_x * right.y + ray_y * up.y,
						forward.z + ray_x * right.z + ray_y * up.z});
				ray = init_ray(ray_origin, ray_dir);
				t = intersect_api(node, *ray);
				if (t > 0)
				{
					color = vec3_to_hex(get_color(node));
					my_mlx_pixel_put(tracer, x, y, color);
				}
				free(ray);
			}
		}
		node = node->next;
	}
	mlx_put_image_to_window(tracer->mlx->mlx, tracer->mlx->mlx_win,
		tracer->img->img, 0, 0);
	return (123);
}
