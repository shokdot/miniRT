/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/03 20:18:32 by tyavroya         ###   ########.fr       */
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
		t_scene_ptr scene, t_node_ptr self)
{
	t_vec3		shadow_origin;
	t_ray		shadow_ray;
	t_node_ptr	node;
	double		t;

	shadow_origin = vec3_add(hit_point, vec3_scale(light_dir, EPSILION));
	shadow_ray = *init_ray(shadow_origin, light_dir); // leaks
	node = scene->figures->head;
	while (node != NULL)
	{
		if (node == self)
		{
			node = node->next;
			continue ;
		}
		t = intersect_api(node, shadow_ray);
		if (t > EPSILION && t < light_distance - EPSILION)
			return (1);
		node = node->next;
	}
	return (0);
}

double	calculate_lighting(t_vec3 hit_point, t_vec3 normal, t_scene_ptr scene,
		t_node_ptr self)
{
	t_vec3	light_vec;
	double	distance;
	t_vec3	light_dir;
	double	cos_theta;
	double	intensity;

	light_vec = vec3_sub(*(scene->light->cords), hit_point);
	distance = vec3_len(light_vec);
	light_dir = vec3_norm(light_vec);
	if (is_occluded(hit_point, light_dir, distance, scene, self))
		return (scene->ambient->ratio);
	normal = vec3_norm(normal);
	cos_theta = fmax(vec3_dot(normal, light_dir), 0.0);
	intensity = scene->ambient->ratio + scene->light->ratio * cos_theta;
	return (fmin(intensity, 1.0));
}

int	render(t_tracer_ptr tracer)
{
	t_vec3		forward;
	t_vec3		up_ref;
	t_vec3		right;
	t_vec3		up;
	t_vec3		ray_origin;
	t_vec3		ray_dir;
	t_ray_ptr	ray;
	double		ray_x;
	double		ray_y;
	double		t;
	double		nearest_t;
	t_node_ptr	node;
	t_node_ptr	nearest_obj;
	t_vec3		hit_point;
	t_vec3		normal;
	double		intensity;
	int			color;

	init_vplane(tracer);
	forward = *(tracer->scene->camera->norm);
	up_ref = (t_vec3){0, 1, 0};
	right = vec3_norm(vec3_cross(forward, up_ref));
	up = vec3_norm(vec3_cross(right, forward));
	ray_origin = *(tracer->scene->camera->cords);
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			ray_x = (x - WIDTH / 2.0) * tracer->scene->vplane->pixel_dx;
			ray_y = (HEIGHT / 2.0 - y) * tracer->scene->vplane->pixel_dy;
			ray_dir = vec3_norm((t_vec3){forward.x + ray_x * right.x + ray_y
					* up.x, forward.y + ray_x * right.y + ray_y * up.y,
					forward.z + ray_x * right.z + ray_y * up.z});
			ray = init_ray(ray_origin, ray_dir);
			nearest_t = INFINITY;
			nearest_obj = NULL;
			node = tracer->scene->figures->head;
			while (node)
			{
				t = intersect_api(node, *ray);
				if (t > EPSILION && t < nearest_t)
				{
					nearest_t = t;
					nearest_obj = node;
				}
				node = node->next;
			}
			if (nearest_obj)
			{
				hit_point = vec3_add(*(ray->origin),
						vec3_scale(*(ray->direction), nearest_t));
				normal = get_normal(nearest_obj, hit_point);
				intensity = calculate_lighting(hit_point, normal, tracer->scene,
						nearest_obj);
				color = vec3_to_hex(get_color(nearest_obj), intensity);
				my_mlx_pixel_put(tracer, x, y, color);
			}
			else
				my_mlx_pixel_put(tracer, x, y, 0xFFFFFF);
			free(ray);
		}
	}
	mlx_put_image_to_window(tracer->mlx->mlx, tracer->mlx->mlx_win,
		tracer->img->img, 0, 0);
	return (123);
}
