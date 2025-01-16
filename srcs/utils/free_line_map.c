/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:13:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/01/16 00:13:14 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_line_map(char **line, t_tracer_ptr tracer)
{
	ft_free((void **)line);
	close(tracer->fd);
	ft_free((void **)&tracer);
}
