/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:58:55 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 18:14:08 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

bool	is_occluded(t_vec3 hit_point, t_vec3 light_dir, double light_distance,
		t_scene_ptr scene, t_node_ptr self)
{
	t_vec3		shadow_origin;
	t_ray_ptr	shadow_ray;
	t_node_ptr	node;
	double		t;

	shadow_origin = vec3_add(hit_point, vec3_scale(light_dir, EPSILION));
	shadow_ray = init_ray(shadow_origin, light_dir);
	node = scene->figures->head;
	while (node != NULL)
	{
		if (node == self)
		{
			node = node->next;
			continue ;
		}
		t = check_intersection(node, *shadow_ray);
		if (t > EPSILION && t < light_distance - EPSILION)
			return (free_ray(shadow_ray), true);
		node = node->next;
	}
	return (free_ray(shadow_ray), false);
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
