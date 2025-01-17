/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 01:17:47 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/17 17:14:51 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_ambient(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != AMBIENT_TOKEN)
	{
		// impl
	}
}

void	parse_light(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != LIGHT_TOKEN)
	{
		// impl
	}
}

void	parse_camera(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != CAMERA_TOKEN)
	{
		// impl
	}
}
