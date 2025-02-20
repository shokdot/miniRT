/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_map_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:21:17 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/19 11:23:11 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	empty_map_free(t_tracer_ptr tracer)
{
	close(tracer->fd);
	clear_lt(&(tracer->figures));
	ft_free((void **)&tracer);
	ft_err("Map: Empty!", 1);
}
