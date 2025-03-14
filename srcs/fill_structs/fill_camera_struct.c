/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_camera_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:49:39 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 11:16:02 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fill_camera_struct(char **line, t_tracer_ptr tracer)
{
	t_camera_ptr	obj;

	obj = (t_camera_ptr)ft_malloc(sizeof(t_camera));
	obj->cords = init_vec3(line[1]);
	obj->norm = init_vec3(line[2]);
	obj->fov = ft_atoi(line[3]);
	tracer->scene->camera = obj;
}
