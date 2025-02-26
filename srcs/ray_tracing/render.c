/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/26 22:53:19 by tigran           ###   ########.fr       */
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

int trace_ray(t_tracer_ptr tracer, t_vec3 origin, t_vec3 dir, double *t)
{
    t_sphere_ptr sphere = (t_sphere_ptr)tracer->scene->figures->head->data;
    t_vec3 oc = vec3_sub(origin, *(sphere->cords)); // Vector from sphere center to ray origin

    double a = vec3_dot(dir, dir);          // Always 1 since dir is normalized
    double b = 2.0 * vec3_dot(oc, dir);
    double radius = sphere->diameter / 2;
    double c = vec3_dot(oc, oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) // No intersection
        return (0);

    // Find closest intersection (smallest positive t)
    *t = (-b - sqrt(discriminant)) / (2.0 * a);
    if (*t < 0) // Intersection behind camera
        return (0);

    return (1); // Hit!
}

int	render(t_tracer_ptr tracer)
{
	init_img(tracer);
	init_vplane(tracer);

    int x, y;
    double ray_x, ray_y;

    // Camera coordinate system
    t_vec3 forward = *(tracer->scene->camera->norm); // (0, 0, 1)
    t_vec3 up_ref = (t_vec3){0, 1, 0};
    t_vec3 right = vec3_norm(vec3_cross(forward, up_ref));
    t_vec3 up = vec3_norm(vec3_cross(right, forward));
	for (y = 0; y < HEIGHT; ++y)
	{
		for (x = 0; x < WIDTH; ++x)
		{
			ray_x = (x - WIDTH / 2.0) * tracer->scene->vplane->pixel_dx;
			ray_y = (HEIGHT / 2.0 - y) * tracer->scene->vplane->pixel_dy;

			t_vec3 ray_origin = *(tracer->scene->camera->cords); // (-50, 0, 20)
			t_vec3 ray_dir = vec3_norm((t_vec3){
				forward.x + ray_x * right.x + ray_y * up.x,
				forward.y + ray_x * right.y + ray_y * up.y,
				forward.z + ray_x * right.z + ray_y * up.z
			});

			double t;
			int hit = trace_ray(tracer, ray_origin, ray_dir, &t);
			int sphere_color = vec3_to_hex(*(((t_sphere_ptr)tracer->scene->figures->head->data)->color));
			int color = hit ? sphere_color : 0x000000; // Sphere color or black
			my_mlx_pixel_put(tracer, x, y, color);
		}
	}
	mlx_put_image_to_window(tracer->mlx->mlx, tracer->mlx->mlx_win,
		tracer->img->img, 0, 0);
	return 123;
}
