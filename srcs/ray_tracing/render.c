/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/27 16:57:03 by tigran           ###   ########.fr       */
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

double intersectSphere(t_ray ray, t_vec3 sphereCenter, double sphereRadius) {
    // Compute oc = ray.origin - sphereCenter
    t_vec3 oc = vec3_sub(*(ray.origin), sphereCenter);

    // Assuming ray.direction is normalized, a = 1, but we compute it in general:
    double a = vec3_dot(*(ray.direction), *(ray.direction));
    double b = 2.0 * vec3_dot(*(ray.direction), oc);
    double c = vec3_dot(oc, oc) - sphereRadius * sphereRadius;

    double discriminant = b * b - 4 * a * c;
	// printf("disc: %f\n", discriminant);
    if (discriminant < 0)
        return -1; // No intersection

    double sqrt_discriminant = sqrt(discriminant);
    double t1 = (-b - sqrt_discriminant) / (2 * a);
    double t2 = (-b + sqrt_discriminant) / (2 * a);

	// printf("\n--------------------------------------------\n");
	// printf("a: %f, b: %f, c: %f, sqrt_disc: %f, t1: %f, t2: %f\n", a, b, c, sqrt_discriminant, t1, t2);
	// printf("\n--------------------------------------------\n");

    // Return the smallest positive t
    if (t1 > 0 && t2 > 0)
        return (t1 < t2) ? t1 : t2;
    else if (t1 > 0)
        return t1;
    else if (t2 > 0)
        return t2;
    else
        return -1;
}


int	render(t_tracer_ptr tracer)
{
	init_img(tracer);
	init_vplane(tracer);

    int x, y;
    double ray_x, ray_y;
	t_ray_ptr ray;
	t_sphere_ptr sphere;

    // Camera coordinate system
    t_vec3 forward = *(tracer->scene->camera->norm); // (0, 0, 1)
    t_vec3 up_ref = (t_vec3){0, 1, 0};
    t_vec3 right = vec3_norm(vec3_cross(forward, up_ref));
    t_vec3 up = vec3_norm(vec3_cross(right, forward));
	t_vec3 ray_origin = *(tracer->scene->camera->cords); // (-50, 0, 20)

	sphere = (t_sphere_ptr)tracer->scene->figures->head->data;
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
			double t = intersectSphere(*ray, *(sphere->cords), sphere->diameter / 2);

			// Optionally, if you want to compute the intersection point:
			// t_vec3 intersectionPoint = calculate(*ray, t);
			free(ray);  // Free the allocated ray
			int sphere_color = vec3_to_hex(*((sphere)->color));
			// If t > 0, then the ray hit the sphere; otherwise, color the pixel black.
			int color = (t > 0) ? sphere_color : 0x000000;
			my_mlx_pixel_put(tracer, x, y, color);
		}
	}
	mlx_put_image_to_window(tracer->mlx->mlx, tracer->mlx->mlx_win,
		tracer->img->img, 0, 0);
	return 123;
}
