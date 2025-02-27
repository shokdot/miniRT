/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/27 23:21:14 by healeksa         ###   ########.fr       */
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
	t_vec3		hit_point;
	t_vec3		normal;
	t_vec3		light_dir;
	double		diffuse;
	double		ambient;
	double		light_intensity;
	t_vec3		base_color;
	t_vec3		ambient_color;
					t_vec3 final_color;
	int			color;

	init_img(tracer);
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
					// Compute the hit point on the object
					hit_point = vec3_add(ray_origin, vec3_scale(ray_dir, t));
					// Get the surface normal at the hit point.
					// (Assume get_normal is implemented per object type.)
					normal = get_normal(node, hit_point);
					// Compute the light direction (from hit point to light position)
					light_dir = vec3_norm(vec3_sub(*(tracer->scene->light->cords),
								hit_point));
					// Diffuse component (Lambertian reflection)
					diffuse = fmax(0, vec3_dot(normal, light_dir));
					// Ambient term from the scene (from your "A" input)
					ambient = tracer->scene->ambient->ratio;
					// Light brightness from the scene (from your "L" input)
					light_intensity = tracer->scene->light->ratio;
					// Get the base color of the object
					base_color = get_color(node);
					// Use the ambient light’s color (e.g.,
						from "A 0.5 255,255,240")
					ambient_color = *(tracer->scene->ambient->color);
					// Compute final color per channel:
					// Multiply the object’s base color by a factor that is the sum of:
					//  
						- The ambient component (modulated by ambient light color)
					//   - The diffuse component (modulated by light brightness)
					final_color.x = base_color.x * (ambient * (ambient_color.x
								/ 255.0) + light_intensity * diffuse);
					final_color.y = base_color.y * (ambient * (ambient_color.y
								/ 255.0) + light_intensity * diffuse);
					final_color.z = base_color.z * (ambient * (ambient_color.z
								/ 255.0) + light_intensity * diffuse);
					// Clamp the final color components to a maximum of 255
					if (final_color.x > 255)
						final_color.x = 255;
					if (final_color.y > 255)
						final_color.y = 255;
					if (final_color.z > 255)
						final_color.z = 255;
					color = vec3_to_hex(final_color);
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
