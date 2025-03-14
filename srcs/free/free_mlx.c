/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:56:39 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 14:11:57 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_mlx(t_mlx_ptr mlx)
{
	free(mlx->mlx);
	free(mlx->mlx_win);
	ft_free((void **)&mlx);
}
