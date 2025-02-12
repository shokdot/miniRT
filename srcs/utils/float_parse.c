/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:49:58 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/12 14:50:55 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

bool	float_parse(char *line)
{
	int		i;
	int		dot_count;
	bool	has_digit;

	has_digit = false;
	dot_count = 0;
	i = 0;
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
