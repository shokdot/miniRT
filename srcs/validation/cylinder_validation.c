/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:29:11 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/15 16:39:12 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	validate_height_diameter(char **line, t_tracer_ptr tracer)
{
	if (!float_parse(line[3]) && !(ft_strlen(line[3]) > 20))
	{
		free_line_map(line, tracer);
		ft_err("Cylinder: diameter!", 3);
	}
	else if (!float_parse(line[4]) && !(ft_strlen(line[4]) > 20))
	{
		free_line_map(line, tracer);
		ft_err("Cylinder: height!", 3);
	}
}

void	validation_cylinder(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != CYLINDER_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Cylinder: arguments!", 3);
	}
	else if (!parse_cords(line[1]))
	{
		free_line_map(line, tracer);
		ft_err("Cylinder: coordinates!", 3);
	}
	else if (!parse_norm_vec(line[2]))
	{
		free_line_map(line, tracer);
		ft_err("Cylinder: coordinates!", 3);
	}
	else if (!parse_color(line[5]))
	{
		free_line_map(line, tracer);
		ft_err("Cylinder: color!", 3);
	}
	validate_height_diameter(line, tracer);
}
