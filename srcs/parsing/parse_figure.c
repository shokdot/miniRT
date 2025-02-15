/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:25:28 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/15 16:19:56 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_sphere(char **line, t_tracer_ptr tracer)
{
	validation_sphere(line, tracer);
}

void	parse_plane(char **line, t_tracer_ptr tracer)
{
	validation_plane(line, tracer);
}

void	parse_cylinder(char **line, t_tracer_ptr tracer)
{
	validation_cylinder(line, tracer);
}
