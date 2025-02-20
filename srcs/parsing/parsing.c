/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:01:38 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/20 20:34:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

bool	determine_object(char **line, t_tracer_ptr tracer)
{
	if (ft_strcmp(line[0], "A") == 0 || ft_strcmp(line[0], "A\n") == 0)
		parse_ambient(line, tracer);
	else if (ft_strcmp(line[0], "L") == 0 || ft_strcmp(line[0], "L\n") == 0)
		parse_light(line, tracer);
	else if (ft_strcmp(line[0], "C") == 0 || ft_strcmp(line[0], "C\n") == 0)
		parse_camera(line, tracer);
	else if (ft_strcmp(line[0], "sp") == 0 || ft_strcmp(line[0], "sp\n") == 0)
		parse_sphere(line, tracer);
	else if (ft_strcmp(line[0], "pl") == 0 || ft_strcmp(line[0], "pl\n") == 0)
		parse_plane(line, tracer);
	else if (ft_strcmp(line[0], "cy") == 0 || ft_strcmp(line[0], "cy") == 0)
		parse_cylinder(line, tracer);
	else
		return (false);
	return (true);
}

void	parse_objects(char **line, t_tracer_ptr tracer, bool *is_empty)
{
	if (skip_check(line))
		return (free_matrix(line));
	else
	{
		*is_empty = false;
		if (!determine_object(line, tracer))
		{
			free_line_map(line, tracer);
			ft_err("Map: Unknown Symbol", 2);
		}
	}
	free_matrix(line);
}

void	parse_line(t_tracer_ptr tracer)
{
	char	*line;
	char	**splited_line;
	bool	is_empty;

	line = NULL;
	is_empty = true;
	while (true)
	{
		line = get_next_line(tracer->fd);
		if (is_line_empty(line))
		{
			if (is_empty)
				empty_map_free(tracer);
			return ;
		}
		tab_to_space(line);
		splited_line = ft_split(line, ' ');
		ft_free((void **)&line);
		if (is_matrix_empty(splited_line))
		{
			free_line_map(splited_line, tracer);
			ft_err("Map: Empty!", 1);
		}
		parse_objects(splited_line, tracer, &is_empty);
	}
}

void	parsing(char *filename, t_tracer_ptr tracer)
{
	tracer->fd = ft_open(filename, O_RDONLY);
	parse_line(tracer);
	close(tracer->fd);
	check_dublicates(tracer);
}
