/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:31:26 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/12 15:56:24 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	is_valid_cords(char *line)
{
	if (*line == '+' || *line == '-')
		line++;
	return (float_parse(line) && !(ft_strlen(line) > 20));
}

bool	parse_cords(char *line)
{
	char	**splited_line;
	int		i;

	i = 0;
	splited_line = ft_split(line, ',');
	if (count_token(splited_line) != CORDS_TOKEN)
		return (free_matrix(splited_line), false);
	while (i < CORDS_TOKEN)
		if (!is_valid_cords(splited_line[i++]))
			return (free_matrix(splited_line), false);
	return (free_matrix(splited_line), true);
}
