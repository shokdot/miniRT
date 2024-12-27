/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:01:38 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/27 22:35:25 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	print_arr(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		printf("%s\n", line[i]);
		i++;
	}
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
		printf("line == %s\n", line[0]);
		*is_empty = 0;
		if (ft_strcmp(line[0], "A") == 0 || ft_strcmp(line[0], "A\n") == 0)
			printf("Ambinet Light\n");
		else if (ft_strcmp(line[0], "L") == 0 || ft_strcmp(line[0], "L\n") == 0)
			printf("Light\n");
		else if (ft_strcmp(line[0], "C") == 0 || ft_strcmp(line[0], "C\n") == 0)
			printf("Camera\n");
		else if (ft_strcmp(line[0], "sp") == 0 || ft_strcmp(line[0],
				"sp\n") == 0)
			printf("Sphere\n");
		else if (ft_strcmp(line[0], "pl") == 0 || ft_strcmp(line[0],
				"pl\n") == 0)
			printf("Plane\n");
		else if (ft_strcmp(line[0], "cy") == 0 || ft_strcmp(line[0], "cy") == 0)
			printf("Cylinder\n");
		else
		{
			close(tracer->fd);
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
		if (!line || !line[0])
		{
			if (is_empty)
			{
				free(tracer);
				ft_err("Map: Empty!", 1);
			}
			return ;
		}
		splited_line = ft_split(line, ' ');
		print_arr(splited_line);
		ft_free((void **)&line);
		parse_objects(splited_line, tracer, &is_empty);
	}
}

void	parsing(char *filename, t_tracer_ptr tracer)
{
	tracer->fd = ft_open(filename, O_RDONLY);
	parse_line(tracer);
	close(tracer->fd);
}
