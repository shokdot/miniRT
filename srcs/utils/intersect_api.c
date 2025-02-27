/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_api.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:47:38 by tigran            #+#    #+#             */
/*   Updated: 2025/02/27 20:19:15 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double intersect_api(t_node_ptr figure, t_ray ray)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == SPHERE)
		return intersect_sphere(ray, ((t_sphere_ptr)obj));
	else if (figure->obj_type == PLANE)
		return intersect_plane(ray, ((t_plane_ptr)obj));
	else if (figure->obj_type == CYLINDER)
		return intersect_cylinder(ray, ((t_cylinder_ptr)obj));
	ft_err("Error in intersect_api", EXIT_FAILURE);
	return (0);
}

t_vec3	get_color(t_node_ptr figure)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == CYLINDER)
		return *(((t_cylinder_ptr)obj)->color);
	else if (figure->obj_type == PLANE)
		return *(((t_plane_ptr)obj)->color);
	else if (figure->obj_type == SPHERE)
		return *(((t_sphere_ptr)obj)->color);
	ft_err("Error in get_color", EXIT_FAILURE);
	return ((t_vec3){0,0,0});
}


t_vec3	get_cords(t_node_ptr figure)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == CYLINDER)
		return *(((t_cylinder_ptr)obj)->cords);
	else if (figure->obj_type == PLANE)
		return *(((t_plane_ptr)obj)->cords);
	else if (figure->obj_type == SPHERE)
		return *(((t_sphere_ptr)obj)->cords);
	ft_err("Error in get_cords", EXIT_FAILURE);
	return ((t_vec3){0,0,0});
}