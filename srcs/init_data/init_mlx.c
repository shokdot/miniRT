/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:04:45 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/28 14:29:42 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	init_mlx(t_tracer_ptr tracer)
{
	tracer->mlx = (t_mlx_ptr)ft_malloc(sizeof(t_mlx));
	tracer->mlx->mlx = mlx_init();
	tracer->mlx->mlx_win = mlx_new_window(tracer->mlx->mlx, WIDTH, HEIGHT,
			"miniRT");
	if (NULL == tracer->mlx->mlx_win || NULL == tracer->mlx->mlx)
	{
		perror("miniRT: mlx error");
		exit(EXIT_FAILURE);
	}
}
