/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:04:45 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 17:01:15 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	init_mlx(t_tracer_ptr tracer)
{
	tracer->mlx = (t_mlx_ptr)ft_malloc(sizeof(t_mlx_ptr));
	tracer->mlx->mlx = mlx_init();
	tracer->mlx->mlx_win = mlx_new_window(tracer->mlx->mlx, WIDTH, HEIGHT,
			"miniRT");
}
