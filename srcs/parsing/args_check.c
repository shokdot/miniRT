/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:41:26 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/30 15:43:42 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

bool	is_rt_file(char *filename)
{
	if (filename && ft_strlen(filename) < 3)
		return (false);
	if (ft_strcmp(filename + (ft_strlen(filename) - 3), ".rt"))
		return (false);
	return (true);
}

void	args_check(int argc, char **argv)
{
	char	*filename;

	if (argc > 2)
		ft_err("Argument: too many!", 1);
	else if (argc <= 1)
		ft_err("Usage: ./miniRT file.rt", 1);
	filename = argv[1];
	if (!is_rt_file(filename))
		ft_err("Filename: specify .rt file", 1);
	return ;
}
