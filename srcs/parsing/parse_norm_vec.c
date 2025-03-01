/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_norm_vec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:08:22 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/01 14:10:59 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	is_valid_vector(char *line)
{
	if (*line == '+' || *line == '-')
		line++;
	return (float_parse(line) && !(ft_strlen(line) > 8));
}

static bool	out_of_range(double value)
{
	if (value < -1 || value > 1)
		return (true);
	return (false);
}

bool	parse_norm_vec(char *line)
{
	char	**splited_line;
	int		i;
	double	x;
	double	y;
	double	z;

	i = 0;
	splited_line = ft_split(line, ',');
	if (count_token(splited_line) != CORDS_TOKEN)
		return (free_matrix(splited_line), false);
	while (i < CORDS_TOKEN)
		if (!is_valid_vector(splited_line[i++]))
			return (free_matrix(splited_line), false);
	x = ft_atof(splited_line[0]);
	y = ft_atof(splited_line[1]);
	z = ft_atof(splited_line[2]);
	if (out_of_range(x) || out_of_range(y) || out_of_range(z))
		return (free_matrix(splited_line), false);
	return (free_matrix(splited_line), true);
}
