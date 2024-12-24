/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:01:38 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/24 19:38:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	parsing(char *filename, t_data_ptr data)
{
	// char	*line;
	data->fd = ft_open(filename, O_RDONLY);
	close(data->fd);
	// line = get_next_line(data->fd);
}
