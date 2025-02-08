/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 01:17:47 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/08 23:04:35 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_ambient(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != AMBIENT_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Ambient: arguments!", 3);
	}
	else if (!parse_ratio(line[1]))
	{
		free_line_map(line, tracer);
		ft_err("Ambient: light ratio!", 3);
	}
	else if (!parse_color(line[2]))
	{
		free_line_map(line, tracer);
		ft_err("Ambient: color!", 3);
	}
}

void	parse_light(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != LIGHT_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Light: arguments!", 3);
	}
	else if (!parse_ratio(line[2]))
	{
		free_line_map(line, tracer);
		ft_err("Light: ratio!", 3);
	}
}

void	parse_camera(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != CAMERA_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Camera: arguments!", 3);
	}
	else if (!parse_fov(line[3]))
	{
		free_line_map(line, tracer);
		ft_err("Camera: FOV!", 3);
	}
}
