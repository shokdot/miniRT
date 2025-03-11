/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_open_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:34:12 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/11 14:34:43 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_open_err(t_tracer_ptr tracer)
{
	close(tracer->fd);
	free_scene(tracer->scene);
	ft_free((void **)&tracer);
	perror("miniRT: Open error");
	exit(EXIT_FAILURE);
}
