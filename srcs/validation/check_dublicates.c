/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dublicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:55:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/21 13:05:43 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	dup_err(t_tracer_ptr tracer)
{
	free_obj_tracer(tracer);
	ft_err("Map: contains duplicates!", 4);
}

void	check_dublicates(t_tracer_ptr tracer)
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
		if (tmp->obj_type == ambinet && ++amb_count > 1)
			dup_err(tracer);
		else if (tmp->obj_type == camera && ++cam_count > 1)
			dup_err(tracer);
		else if (tmp->obj_type == light && ++light_count > 1)
			dup_err(tracer);
		tmp = tmp->next;
	}
}
