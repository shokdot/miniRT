/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_figure_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:00:22 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/04 18:18:13 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	get_figure_normal(t_node_ptr node, t_vec3 hit_point)
{
	void	*obj;

	obj = node->data;
	if (node->obj_type == SPHERE)
		return (vec3_norm(vec3_sub(hit_point, *((t_sphere_ptr)obj)->cords)));
	else if (node->obj_type == PLANE)
		return (*((t_plane_ptr)obj)->norm);
	else if (node->obj_type == CYLINDER)
		return (get_cylinder_normal((t_cylinder_ptr)obj, hit_point));
	return ((t_vec3){0, 0, 0});
}
