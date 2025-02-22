/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:04:04 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/22 23:01:24 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fill_plane_struct(char **line, t_tracer_ptr tracer)
{
	t_plane_ptr	obj;

	obj = (t_plane_ptr)ft_malloc(sizeof(t_plane));
	obj->cords = init_vec3(line[1]);
	obj->norm = init_vec3(line[2]);
	obj->color = init_vec3(line[3]);
	push_back_mv_lt(tracer->figures, obj, PLANE);
}
