/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/01 15:52:42 by tyavroya         ###   ########.fr       */
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

int	is_occluded(t_vec3 hit_point, t_vec3 light_dir, double light_distance,
		t_scene_ptr scene)
{
	const double	epsilon = 0.001;
	t_vec3			shadow_origin;
	t_ray			shadow_ray;
	t_node_ptr		node;
	double			t;

	shadow_origin = vec3_add(hit_point, vec3_scale(light_dir, epsilon));
	shadow_ray.origin = &shadow_origin;
	shadow_ray.direction = &light_dir;
	node = scene->figures->head;
	while (node != NULL)
	{
		t = intersect_api(node, shadow_ray);
		if (t > 0 && t < light_distance)
			return (0);
		node = node->next;
	}
	return (1);
}

double	calculate_lighting(t_vec3 hit_point, t_vec3 normal, t_scene_ptr scene)
{
	double	distance;
	t_vec3	light_dir;
	double	cos_theta;
	double	intensity;
	t_vec3	light_vec;

	light_vec = vec3_sub(*(scene->light->cords), hit_point);
	distance = vec3_len(light_vec);
	light_dir = vec3_norm(light_vec);
	if (is_occluded(hit_point, light_dir, distance, scene))
		return (1);
	cos_theta = fabs(vec3_dot(normal, light_dir));
	// attenuation = 1.0 / (distance * distance);
	intensity = scene->ambient->ratio * scene->light->ratio * cos_theta;
	// printf("angle: %f, attenuation: %f, intensity: %f\n", cos_theta,
	// 	attenuation, intensity);
	return (intensity);
}

int	render(t_tracer_ptr tracer)
{
	t_vec3		up_ref;
	t_vec3		right;
	t_vec3		up;
	t_node_ptr	figure;
	double		ray_x;
	double		ray_y;
	t_vec3		ray_dir;
	t_ray_ptr	ray;
	double		t;
	int			color;
	t_vec3		hit_point;
	double		intensity;

	init_vplane(tracer);
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
	figure = tracer->scene->figures->head;
	while (figure != NULL)
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
				t = intersect_api(figure, *ray);
				if (t > 0)
				{
					hit_point = vec3_add(*(ray->origin),
							vec3_scale(*(ray->direction), t));
					intensity = calculate_lighting(hit_point, ray_dir,
							tracer->scene);
					color = vec3_to_hex(get_color(figure), intensity);
					my_mlx_pixel_put(tracer, x, y, color);
				}
				free(ray);
			}
		}
		figure = figure->next;
	}
	mlx_put_image_to_window(tracer->mlx->mlx, tracer->mlx->mlx_win,
		tracer->img->img, 0, 0);
	return (123);
}
