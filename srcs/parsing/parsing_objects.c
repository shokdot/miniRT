/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 01:17:47 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/17 20:29:22 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_ambient(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != AMBIENT_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Ambient arguments!", 3);
	}
}

void	parse_light(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != LIGHT_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Some Error!", 3);
	}
}

void	parse_camera(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != CAMERA_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Some Error!", 3);
	}
}
