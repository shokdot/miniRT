/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:59:20 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/17 22:25:42 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	is_valid_fov(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (false);
		i++;
	}
	if (i > 3)
		return (false);
	return (true);
}

static bool	out_of_range_fov(int value)
{
	if (value < 0 || value > 180)
		return (true);
	return (false);
}

bool	parse_fov(char *line)
{
	int	fov;

	if (!is_valid_fov(line))
		return (false);
	fov = ft_atoi(line);
	if (out_of_range_fov(fov))
		return (false);
	return (true);
}
