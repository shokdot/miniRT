/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_figure_cords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:52:31 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/04 17:53:20 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	get_figure_cords(t_node_ptr figure)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == SPHERE)
		return (*(((t_sphere_ptr)obj)->cords));
	else if (figure->obj_type == PLANE)
		return (*(((t_plane_ptr)obj)->cords));
	else if (figure->obj_type == CYLINDER)
		return (*(((t_cylinder_ptr)obj)->cords));
	return ((t_vec3){0, 0, 0});
}
