/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:53:08 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 17:54:30 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_lib(t_tracer_ptr tracer)
{
	mlx_destroy_image(tracer->mlx->mlx, tracer->img->img);
	mlx_clear_window(tracer->mlx->mlx, tracer->mlx->mlx_win);
	mlx_destroy_window(tracer->mlx->mlx, tracer->mlx->mlx_win);
	ft_free((void **)&tracer->mlx);
	ft_free((void **)&tracer->img);
}
