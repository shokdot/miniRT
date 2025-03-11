/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:36:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/11 16:10:16 by healeksa         ###   ########.fr       */
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
	int	flag;

	i = 0;
	flag = 0;
	while (line[i])
	{
		if (is_spaces(line[i]))
			line[i] = ' ';
		else if (line[i] != ' ' && ft_isprint(line[i]))
			flag = 1;
		else if (i != 0 && line[i] == '\n' && flag == 1)
			line[i] = '\0';
		++i;
	}
}
