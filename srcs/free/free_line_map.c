/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:13:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 14:57:53 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_line_map(char **line, t_tracer_ptr tracer)
{
	free_matrix(line);
	line = NULL;
	close(tracer->fd);
	free_scene(tracer->scene);
	ft_free((void **)&tracer);
}
