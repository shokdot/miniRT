/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:25:28 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/29 17:34:25 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_sphere(char **line, t_tracer_ptr tracer UNUSED)
{
	(void)line;
	printf("Sphere\n");
}

void	parse_plane(char **line, t_tracer_ptr tracer UNUSED)
{
	(void)line;
	printf("Plane\n");
}

void	parse_cylinder(char **line, t_tracer_ptr tracer UNUSED)
{
	(void)line;
	printf("Cylinder\n");
}
