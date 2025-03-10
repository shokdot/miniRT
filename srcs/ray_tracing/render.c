/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 16:49:21 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

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
		t = check_intersection(node, shadow_ray);
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

void	render(t_tracer_ptr tracer)
{
	t_ray_ptr	ray;
	double		t;
	double		nearest_t;
	t_node_ptr	node;
	t_node_ptr	nearest_obj;
	t_vec3		hit_point;
	t_vec3		normal;
	double		intensity;
	int			color;
	int			y;
	int			x;

	init_vplane(tracer);
	init_vcam(tracer);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ray_calculate(x, y, tracer);
			nearest_t = INFINITY;
			nearest_obj = NULL;
			node = tracer->scene->figures->head;
			while (node)
			{
				t = check_intersection(node, *ray);
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
				normal = get_figure_normal(nearest_obj, hit_point);
				intensity = calculate_lighting(hit_point, normal, tracer->scene,
						nearest_obj);
				color = vec3_to_hex(get_figure_color(nearest_obj), intensity);
				put_pixel(tracer, x, y, color);
			}
			else
				put_pixel(tracer, x, y, 0xFFFFFF);
			free(ray);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(tracer->mlx->mlx, tracer->mlx->mlx_win,
		tracer->img->img, 0, 0);
}
