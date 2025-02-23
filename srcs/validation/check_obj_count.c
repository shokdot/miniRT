/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:55:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 11:20:08 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	dup_err(t_tracer_ptr tracer, char *msg)
{
	free_obj_tracer(tracer);
	ft_err(msg, 4);
}

void	check_obj_count(t_tracer_ptr tracer)
{
	t_scene_ptr	scene;

	scene = tracer->scene;
	if (scene->amb_count != 1)
		dup_err(tracer, "Map: Missing Ambient Light!");
	else if (scene->cam_count != 1)
		dup_err(tracer, "Map: Missing Camera!");
	else if (scene->lgt_count != 1)
		dup_err(tracer, "Map: Missing Light!");
}
