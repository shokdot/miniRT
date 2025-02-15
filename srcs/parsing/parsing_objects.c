/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 01:17:47 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/15 15:26:28 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_ambient(char **line, t_tracer_ptr tracer)
{
	validation_ambient(line, tracer);
	// parsing fill struct
}

void	parse_light(char **line, t_tracer_ptr tracer)
{
	validation_light(line, tracer);
	// parsing fill struct
}

void	parse_camera(char **line, t_tracer_ptr tracer)
{
	validation_camera(line, tracer);
	// parsing fill struct
}
