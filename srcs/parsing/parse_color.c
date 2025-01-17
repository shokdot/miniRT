/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:30:58 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/17 21:13:57 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	is_valid_color(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(ft_isdigit((int)line[i]) || line[i] == ','))
			return (false);
		i++;
	}
	return (true);
}

static bool	out_of_range(int value)
{
	if (value < 0 || value > 255)
		return (true);
	return (false);
}

bool	parse_color(char *line)
{
	char	**splited_color;
	int		red;
	int		green;
	int		blue;

	splited_color = NULL;
	if (!is_valid_color(line))
		return (false);
	splited_color = ft_split(line, ',');
	if (count_token(splited_color) != COLOR_TOKEN)
		return (free_matrix(splited_color), false);
	red = ft_atoi(splited_color[0]);
	green = ft_atoi(splited_color[1]);
	blue = ft_atoi(splited_color[2]);
	if (out_of_range(red) || out_of_range(green) || out_of_range(blue))
		return (free_matrix(splited_color), false);
	return (true);
}
