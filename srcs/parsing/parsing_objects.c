/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 01:17:47 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/30 16:08:18 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	token_count(char **line, int count)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (count != i)
	{
		ft_err("Wrong parameter", 2);
	}
}

void	parse_ambient(char **line, t_tracer_ptr tracer UNUSED)
{
	token_count(line, 3);
	printf("Ambinet Light\n");
}

void	parse_light(char **line, t_tracer_ptr tracer UNUSED)
{
	(void)line;
	token_count(line, 4);
	printf("Light\n");
}

void	parse_camera(char **line, t_tracer_ptr tracer UNUSED)
{
	(void)line;
	token_count(line, 4);
	printf("Camera\n");
}
