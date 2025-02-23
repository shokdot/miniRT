/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 01:17:47 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 16:00:42 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_ambient(char **line, t_tracer_ptr tracer)
{
	if (tracer->scene->amb_count > 0)
	{
		free_line_map(line, tracer);
		ft_err("Map: Ambient Light Duplicates", 4);
	}
	tracer->scene->amb_count++;
	validation_ambient(line, tracer);
	fill_ambient_struct(line, tracer);
}

void	parse_light(char **line, t_tracer_ptr tracer)
{
	if (tracer->scene->lgt_count > 0)
	{
		free_line_map(line, tracer);
		ft_err("Map: Light Duplicates", 4);
	}
	tracer->scene->lgt_count++;
	validation_light(line, tracer);
	fill_light_struct(line, tracer);
}

void	parse_camera(char **line, t_tracer_ptr tracer)
{
	if (tracer->scene->cam_count > 0)
	{
		free_line_map(line, tracer);
		ft_err("Map: Camera Duplicates", 4);
	}
	tracer->scene->cam_count++;
	validation_camera(line, tracer);
	fill_camera_struct(line, tracer);
}
