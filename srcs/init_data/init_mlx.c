/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:04:45 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/21 15:45:27 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_mlx_ptr	init_mlx(void)
{
	t_mlx_ptr	mlx;

	mlx = (t_mlx_ptr)ft_malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1920, 1080, "miniRT");
	return (mlx);
}
