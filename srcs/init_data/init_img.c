/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:28:09 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/28 14:29:26 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	init_img(t_tracer_ptr tracer)
{
	tracer->img = (t_img_ptr)ft_malloc(sizeof(t_img));
	tracer->img->img = mlx_new_image(tracer->mlx->mlx, WIDTH, HEIGHT);
	tracer->img->img_data = mlx_get_data_addr(tracer->img->img,
			&tracer->img->bpp, &tracer->img->size_line, &tracer->img->endian);
	if (NULL == tracer->img->img || NULL == tracer->img->img_data)
	{
		perror("miniRT: mlx error");
		exit(EXIT_FAILURE);
	}
}
