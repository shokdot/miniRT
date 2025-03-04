/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:47:38 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/04 18:00:20 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	check_intersection(t_node_ptr figure, t_ray ray)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == SPHERE)
		return (intersect_sphere(ray, ((t_sphere_ptr)obj)));
	else if (figure->obj_type == PLANE)
		return (intersect_plane(ray, ((t_plane_ptr)obj)));
	else if (figure->obj_type == CYLINDER)
		return (intersect_cylinder(ray, ((t_cylinder_ptr)obj)));
	return (0);
}
