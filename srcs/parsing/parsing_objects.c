/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 01:17:47 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 00:13:02 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_ambient(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != 3)
	{
		free_line_map(line, tracer);
		ft_err("Ambinet", 3);
	}
}

void	parse_light(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != 3)
	{
		free_line_map(line, tracer);
		ft_err("light", 3);
	}
}

void	parse_camera(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != 4)
	{
		free_line_map(line, tracer);
		ft_err("Ambinet", 3);
	}
}
