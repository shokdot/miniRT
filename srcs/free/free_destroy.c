/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:13:58 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/28 20:15:31 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_destroy(t_tracer_ptr tracer)
{
	// mlx_clear_window(tracer->mlx->mlx, tracer->mlx->mlx_win);
	// mlx_destroy_image(tracer->mlx->mlx, tracer->img->img);
	mlx_destroy_window(tracer->mlx->mlx, tracer->mlx->mlx_win);
	free_obj_tracer(tracer);
	exit(0);
}
