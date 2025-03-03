/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_apis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:47:38 by tigran            #+#    #+#             */
/*   Updated: 2025/03/03 18:30:19 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	intersect_api(t_node_ptr figure, t_ray ray)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == SPHERE)
		return (intersect_sphere(ray, ((t_sphere_ptr)obj)));
	else if (figure->obj_type == PLANE)
		return (intersect_plane(ray, ((t_plane_ptr)obj)));
	else if (figure->obj_type == CYLINDER)
		return (intersect_cylinder(ray, ((t_cylinder_ptr)obj)));
	ft_err("Error in intersect_api", EXIT_FAILURE); // nowo
	return (0);
}

t_vec3	get_color(t_node_ptr figure)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == CYLINDER)
		return (*(((t_cylinder_ptr)obj)->color));
	else if (figure->obj_type == PLANE)
		return (*(((t_plane_ptr)obj)->color));
	else if (figure->obj_type == SPHERE)
		return (*(((t_sphere_ptr)obj)->color));
	ft_err("Error in get_color", EXIT_FAILURE);
	return ((t_vec3){0, 0, 0});
}

t_vec3	get_cords(t_node_ptr figure)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == CYLINDER)
		return (*(((t_cylinder_ptr)obj)->cords));
	else if (figure->obj_type == PLANE)
		return (*(((t_plane_ptr)obj)->cords));
	else if (figure->obj_type == SPHERE)
		return (*(((t_sphere_ptr)obj)->cords));
	ft_err("Error in get_cords", EXIT_FAILURE);
	return ((t_vec3){0, 0, 0});
}

t_vec3	get_normal(t_node_ptr node, t_vec3 hit_point)
{
	void	*obj;
	t_vec3	cp;
	double	proj;
	t_vec3	axis_point;
	t_vec3	lateral_normal;
	double	half_height;
	t_vec3	norm_cylinder;

	obj = node->data;
	if (node->obj_type == SPHERE)
		return (vec3_norm(vec3_sub(hit_point, *((t_sphere_ptr)obj)->cords)));
	else if (node->obj_type == PLANE)
		return (*((t_plane_ptr)obj)->norm);
	else if (node->obj_type == CYLINDER)
	{
		cp = vec3_sub(hit_point, *((t_cylinder_ptr)obj)->cords);
		norm_cylinder = vec3_norm(*(((t_cylinder_ptr)obj)->norm));
		proj = vec3_dot(cp, norm_cylinder);
		axis_point = vec3_add(*(((t_cylinder_ptr)obj)->cords),
				vec3_scale(*(((t_cylinder_ptr)obj)->norm), proj));
		lateral_normal = vec3_norm(vec3_sub(hit_point, axis_point));
		half_height = ((t_cylinder_ptr)obj)->height / 2.0;
		if (fabs(proj) >= half_height - EPSILION)
		{
			if (proj > 0)
				return (*(((t_cylinder_ptr)obj)->norm));
			else
				return (vec3_negate(*(((t_cylinder_ptr)obj)->norm)));
		}
		return (lateral_normal);
	}
	return ((t_vec3){0, 0, 0});
}
