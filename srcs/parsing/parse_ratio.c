/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:18:22 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/08 22:47:55 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	is_valid_ratio(char *line)
{
	int	i;
	int	dot_count;

	dot_count = 0;
	i = 0;
	if (ft_strlen(line) > 8)
		return (false);
	while (line[i])
	{
		if (line[i] == '.' && ++dot_count > 1)
			return (false);
		if (!(ft_isdigit(line[i]) || line[i] == '.'))
			return (false);
		i++;
	}
	return (true);
}

bool	parse_ratio(char *line)
{
	double	ratio;

	if (!is_valid_ratio(line))
		return (false);
	ratio = ft_atof(line);
	if (ratio < 0.0 || ratio > 1.0)
		return (false);
	return (true);
}
