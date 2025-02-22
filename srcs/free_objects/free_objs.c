/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:36:51 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/22 23:01:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_objs(t_list_ptr objs)
{
	t_node_ptr	tmp;

	tmp = objs->head;
	while (tmp)
	{
		if (tmp->obj_type == AMBIENT)
			free_ambient((t_ambient_ptr)tmp->data);
		else if (tmp->obj_type == CAMERA)
			free_camera((t_camera_ptr)tmp->data);
		else if (tmp->obj_type == CYLINDER)
			free_cylinder((t_cylinder_ptr)tmp->data);
		else if (tmp->obj_type == LIGHT)
			free_light((t_light_ptr)tmp->data);
		else if (tmp->obj_type == PLANE)
			free_plane((t_plane_ptr)tmp->data);
		else if (tmp->obj_type == SPHERE)
			free_sphere((t_sphere_ptr)tmp->data);
		tmp = tmp->next;
	}
}
