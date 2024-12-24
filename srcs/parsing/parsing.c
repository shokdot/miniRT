/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:01:38 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/25 02:58:34 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parse_objects(char **line, t_tracer_ptr tracer)
{
	if (ft_strcmp(line[0], "\n") == 0 || line[0][0] == '#')
	{
		free_matrix(line);
		return ;
	}
	if (ft_strcmp(line[0], "A") == 0)
		printf("Ambinet Light\n");
	else if (ft_strcmp(line[0], "L") == 0)
		printf("Light\n");
	else if (ft_strcmp(line[0], "C") == 0)
		printf("Camera\n");
	else if (ft_strcmp(line[0], "sp") == 0)
		printf("Sphere\n");
	else if (ft_strcmp(line[0], "pl") == 0)
		printf("Plane\n");
	else if (ft_strcmp(line[0], "cy") == 0)
		printf("Cylinder\n");
	else
	{
		close(tracer->fd);
		ft_free((void **)&tracer);
		ft_err("Map: Unknown Symbol", 2);
	}
	free_matrix(line);
}

void	parse_line(t_tracer_ptr tracer)
{
	char	*line;
	char	**splited_line;

	line = NULL;
	while (1)
	{
		line = get_next_line(tracer->fd);
		if (!line || !line[0])
		{
			free(tracer); // check in case of empty error and leaks......
			return ;
			// ft_err("some problem", 2);
		}
		splited_line = ft_split(line, ' ');
		parse_objects(splited_line, tracer);
		ft_free((void **)&line); /// check if unknown symbol and # give
	}
}

void	parsing(char *filename, t_tracer_ptr tracer)
{
	tracer->fd = ft_open(filename, O_RDONLY);
	parse_line(tracer);
	close(tracer->fd);
}
