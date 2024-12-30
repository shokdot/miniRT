/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:36:13 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/30 15:41:20 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	is_spaces(char c)
{
	return (c == '\t' || c == '\r' || c == '\v' || c == '\f');
}

void	tab_to_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_spaces(line[i]))
		{
			line[i] = ' ';
		}
		i++;
	}
}
