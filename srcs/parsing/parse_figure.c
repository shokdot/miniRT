/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:25:28 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/18 18:00:37 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_sphere(char **line, t_tracer_ptr tracer)
{
	validation_sphere(line, tracer);
	fill_sphere_struct(line, tracer);
}

void	parse_plane(char **line, t_tracer_ptr tracer)
{
	validation_plane(line, tracer);
	fill_plane_struct(line, tracer);
}

void	parse_cylinder(char **line, t_tracer_ptr tracer)
{
	validation_cylinder(line, tracer);
	fill_cylinder_struct(line, tracer);
}
