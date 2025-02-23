/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:13:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/22 23:16:21 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_line_map(char **line, t_tracer_ptr tracer)
{
	free_matrix(line);
	line = NULL;
	close(tracer->fd);
	ft_free((void **)&tracer->mlx);
	clear_lt(&(tracer->scene->figures));
	ft_free((void **)&tracer);
}
