/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:18:22 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/11 18:44:02 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	is_valid_ratio(char *line)
{
	int		i;
	int		dot_count;
	bool	has_digit;

	dot_count = 0;
	has_digit = false;
	i = 0;
	if (ft_strlen(line) > 8)
		return (false);
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			has_digit = true;
		if (line[i] == '.' && ++dot_count > 1)
			return (false);
		if (!(ft_isdigit(line[i]) || line[i] == '.'))
			return (false);
		i++;
	}
	return (has_digit);
}

static bool	out_of_range(double ratio)
{
	if (ratio < 0.0 || ratio > 1.0)
		return (true);
	return (false);
}

bool	parse_ratio(char *line)
{
	double	ratio;

	if (!is_valid_ratio(line))
		return (false);
	ratio = ft_atof(line);
	if (out_of_range(ratio))
		return (false);
	return (true);
}
