/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:55:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/22 23:00:54 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	dup_err(t_tracer_ptr tracer, int typ)
{
	free_obj_tracer(tracer);
	if (typ == 1)
		ft_err("Map: contains duplicates!", 4);
	ft_err("Map: there is'nt Light, Ambient or Camera!", 4);
}

void	check_obj_count(t_tracer_ptr tracer)
{
	t_node_ptr	tmp;
	int			amb_count;
	int			cam_count;
	int			light_count;

	amb_count = 0;
	cam_count = 0;
	light_count = 0;
	tmp = tracer->figures->head;
	while (tmp)
	{
		if (tmp->obj_type == AMBIENT)
			++amb_count;
		else if (tmp->obj_type == CAMERA)
			++cam_count;
		else if (tmp->obj_type == LIGHT)
			++light_count;
		tmp = tmp->next;
	}
	if (amb_count < 1 || cam_count < 1 || light_count < 1)
		dup_err(tracer, 0);
	else if (amb_count > 1 || cam_count > 1 || light_count > 1)
		dup_err(tracer, 1);
}
