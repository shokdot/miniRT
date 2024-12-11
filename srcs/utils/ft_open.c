/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:38:23 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/11 11:13:29 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_open(const char *pathname, int flags)
{
	int	fd;

	fd = open(pathname, flags);
	if (fd < 0)
	{
		perror("miniRT: open error");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
