/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_map_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:21:17 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/29 16:32:57 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	empty_map_free(t_tracer_ptr tracer)
{
	close(tracer->fd);
	ft_free((void **)&tracer);
	ft_err("Map: Empty!", 1);
}
