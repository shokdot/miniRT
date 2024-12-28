/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:01:38 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/28 22:25:45 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

bool	determine_object(char **line)
{
	if (ft_strcmp(line[0], "A") == 0 || ft_strcmp(line[0], "A\n") == 0)
		printf("Ambinet Light\n");
	else if (ft_strcmp(line[0], "L") == 0 || ft_strcmp(line[0], "L\n") == 0)
		printf("Light\n");
	else if (ft_strcmp(line[0], "C") == 0 || ft_strcmp(line[0], "C\n") == 0)
		printf("Camera\n");
	else if (ft_strcmp(line[0], "sp") == 0 || ft_strcmp(line[0], "sp\n") == 0)
		printf("Sphere\n");
	else if (ft_strcmp(line[0], "pl") == 0 || ft_strcmp(line[0], "pl\n") == 0)
		printf("Plane\n");
	else if (ft_strcmp(line[0], "cy") == 0 || ft_strcmp(line[0], "cy") == 0)
		printf("Cylinder\n");
	else
		return (false);
	return (true);
}

void	parse_objects(char **line, t_tracer_ptr tracer, bool *is_empty)
{
	if (ft_strcmp(line[0], "\n") == 0 || line[0][0] == '#')
	{
		free_matrix(line);
		return ;
	}
	else
	{
		*is_empty = 0;
		if (!determine_object(line))
		{
			close(tracer->fd);
			free_matrix(line);
			ft_free((void **)&tracer);
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
	is_empty = 1;
	while (1)
	{
		line = get_next_line(tracer->fd);
		if (is_line_empty(line))
		{
			if (is_empty)
			{
				close(tracer->fd);
				ft_free((void **)&tracer);
				ft_err("Map: Empty!", 1);
			}
			return ;
		}
		splited_line = ft_split(line, ' ');
		ft_free((void **)&line);
		if (is_matrix_empty(splited_line))
		{
			free_matrix(splited_line);
			close(tracer->fd);
			ft_free((void **)&tracer);
			ft_err("Map: Empty!", 1);
		}
		print_matrix(splited_line);
		parse_objects(splited_line, tracer, &is_empty);
	}
}

void	parsing(char *filename, t_tracer_ptr tracer)
{
	tracer->fd = ft_open(filename, O_RDONLY);
	parse_line(tracer);
	close(tracer->fd);
}
