/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_empty_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:21:17 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 14:56:32 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_empty_map(t_tracer_ptr tracer)
{
	close(tracer->fd);
	free_scene(tracer->scene);
	ft_free((void **)&tracer);
	ft_err("Map: Empty!", 1);
}
