/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:23:18 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 11:23:36 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_figures(t_list_ptr figures)
{
	t_node_ptr	tmp;

	tmp = figures->head;
	while (tmp)
	{
		if (tmp->obj_type == CYLINDER)
			free_cylinder((t_cylinder_ptr)tmp->data);
		else if (tmp->obj_type == PLANE)
			free_plane((t_plane_ptr)tmp->data);
		else if (tmp->obj_type == SPHERE)
			free_sphere((t_sphere_ptr)tmp->data);
		tmp = tmp->next;
	}
}
