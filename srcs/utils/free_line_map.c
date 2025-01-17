/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:13:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/17 17:28:04 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_line_map(char **line, t_tracer_ptr tracer)
{
	free_matrix(line);
	line = NULL;
	close(tracer->fd);
	ft_free((void **)&tracer);
}
