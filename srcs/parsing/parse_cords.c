/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:31:26 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/11 00:27:34 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	is_valid_cords(char *line)
{
	int		i;
	int		dot_count;
	bool	has_digit;

	has_digit = false;
	dot_count = 0;
	i = 0;
	if (line[i] == '+' || line[i] == '-')
		i++;
	while (line[i])
	{
		if (!(ft_isdigit(line[i]) || line[i] == '.'))
			return (false);
		else if (ft_isdigit(line[i]))
			has_digit = true;
		else if (line[i] == '.' && ++dot_count > 1)
			return (false);
		i++;
	}
	return (has_digit);
}

bool	parse_cords(char *line)
{
	char	**splited_line;
	int		i;

	i = 0;
	splited_line = ft_split(line, ',');
	if (count_token(splited_line) != 3) // fix
		return (false);
	while (i < 3)
		if (!is_valid_cords(splited_line[i++]))
			return (false);
	print_matrix(splited_line);
	return (true);
}
