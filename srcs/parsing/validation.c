/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:22:20 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/15 16:49:15 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	validation_ambient(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != AMBIENT_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Ambient: arguments!", 3);
	}
	else if (!parse_ratio(line[1]))
	{
		free_line_map(line, tracer);
		ft_err("Ambient: light ratio!", 3);
	}
	else if (!parse_color(line[2]))
	{
		free_line_map(line, tracer);
		ft_err("Ambient: color!", 3);
	}
}

void	validation_light(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != LIGHT_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Light: arguments!", 3);
	}
	else if (!parse_cords(line[1]))
	{
		free_line_map(line, tracer);
		ft_err("Light: coordinates!", 3);
	}
	else if (!parse_ratio(line[2]))
	{
		free_line_map(line, tracer);
		ft_err("Light: ratio!", 3);
	}
}

void	validation_camera(char **line, t_tracer_ptr tracer)
{
	if (count_token(line) != CAMERA_TOKEN)
	{
		free_line_map(line, tracer);
		ft_err("Camera: arguments!", 3);
	}
	else if (!parse_cords(line[1]))
	{
		free_line_map(line, tracer);
		ft_err("Camera: coordinates!", 3);
	}
	else if (!parse_norm_vec(line[2]))
	{
		free_line_map(line, tracer);
		ft_err("Camera: normalized vector!", 3);
	}
	else if (!parse_fov(line[3]))
	{
		free_line_map(line, tracer);
		ft_err("Camera: FOV!", 3);
	}
}

void	validation_sphere(char **line, t_tracer_ptr tracer)
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
	else if (!float_parse(line[2]) && !(ft_strlen(line[2]) > 20))
	{
		free_line_map(line, tracer);
		ft_err("Sphere: diameter!", 3);
	}
	else if (!parse_color(line[3]))
	{
		free_line_map(line, tracer);
		ft_err("Sphere: color!", 3);
	}
}

void	validation_plane(char **line, t_tracer_ptr tracer)
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
