/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:48:39 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/17 21:36:26 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static bool	comment_check(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(line[i], '#'))
			return (true);
		i++;
	}
	return (false);
}

bool	skip_check(char **line)
{
	if (ft_strcmp(line[0], "\n") == 0 || comment_check(line))
		return (true);
	return (false);
}
