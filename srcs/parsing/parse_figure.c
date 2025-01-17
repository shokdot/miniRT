/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:25:28 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/17 17:15:20 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_sphere(char **line, t_tracer_ptr tracer UNUSED)
{
	if (count_token(line) != SPHERE_TOKEN)
	{
		// impl
	}
}

void	parse_plane(char **line, t_tracer_ptr tracer UNUSED)
{
	if (count_token(line) != PLANE_TOKEN)
	{
		// impl
	}
}

void	parse_cylinder(char **line, t_tracer_ptr tracer UNUSED)
{
	if (count_token(line) != CYLINDER_TOKEN)
	{
		// impl
	}
}
