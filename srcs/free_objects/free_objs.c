/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:36:51 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/21 13:00:23 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_objs(t_list_ptr objs)
{
	t_node_ptr	tmp;

	tmp = objs->head;
	while (tmp)
	{
		if (tmp->obj_type == ambinet)
			free_ambient((t_ambient_ptr)tmp->data);
		else if (tmp->obj_type == camera)
			free_camera((t_camera_ptr)tmp->data);
		else if (tmp->obj_type == cylinder)
			free_cylinder((t_cylinder_ptr)tmp->data);
		else if (tmp->obj_type == light)
			free_light((t_light_ptr)tmp->data);
		else if (tmp->obj_type == plane)
			free_plane((t_plane_ptr)tmp->data);
		else if (tmp->obj_type == sphere)
			free_sphere((t_sphere_ptr)tmp->data);
		tmp = tmp->next;
	}
}
