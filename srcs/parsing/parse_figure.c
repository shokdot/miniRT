/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:25:28 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/12 16:34:47 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_sphere(char **line, t_tracer_ptr tracer UNUSED)
{
	if (count_token(line) != SPHERE_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Sphere: arguments!", 3);
	}
	else if (!parse_cords(line[1]))
	{
		free_line_map(line, tracer);
		ft_err("Sphere: coordinates!", 3);
	}
	else if (!parse_color(line[3]))
	{
		free_line_map(line, tracer);
		ft_err("Sphere: color!", 3);
	}
}

void	parse_plane(char **line, t_tracer_ptr tracer UNUSED)
{
	if (count_token(line) != PLANE_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Plane: arguments!", 3);
	}
	else if (!parse_cords(line[1]))
	{
		free_line_map(line, tracer);
		ft_err("Plane: coordinates!", 3);
	}
	else if (!parse_norm_vec(line[2]))
	{
		free_line_map(line, tracer);
		ft_err("Plane: coordinates!", 3);
	}
	else if (!parse_color(line[3]))
	{
		free_line_map(line, tracer);
		ft_err("Plane: color!", 3);
	}
}

void	parse_cylinder(char **line, t_tracer_ptr tracer UNUSED)
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
	else if (!parse_color(line[5]))
	{
		free_line_map(line, tracer);
		ft_err("Cylinder: color!", 3);
	}
}
