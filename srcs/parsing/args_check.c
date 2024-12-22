/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:41:26 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/22 22:53:41 by healeksa         ###   ########.fr       */
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

	(void)argv;
	if (argc > 2)
		ft_err("Arguments too many!", 1);
	else if (argc <= 1)
		ft_err("Usage: ./miniRT file.rt", 1);
	filename = argv[1];
	if (!is_rt_file(filename))
		ft_err("Please specify .rt file", 1);
	return ;
}
