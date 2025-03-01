/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:12:54 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/28 20:13:57 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	mlx_handler(t_tracer_ptr tracer)
{
	mlx_hook(tracer->mlx->mlx_win, ON_DESTROY, NO_EVENT, (void *)free_destroy,
		tracer);
	mlx_loop(tracer->mlx->mlx);
}
