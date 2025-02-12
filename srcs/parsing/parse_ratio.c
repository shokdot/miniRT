/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:18:22 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/12 14:57:46 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	is_valid_ratio(char *line)
{
	return (float_parse(line) && !(ft_strlen(line) > 8));
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
