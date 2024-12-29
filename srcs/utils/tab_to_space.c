/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:36:13 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/29 18:42:08 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	is_spacec(char c)
{
	return (c == '\t' || c == '\r' || c == '\v' || c == '\f');
}

void	tab_to_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_spacec(line[i]))
		{
			line[i] = ' ';
		}
		i++;
	}
}
