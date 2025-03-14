/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:38:14 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/25 16:19:40 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_tracer_ptr	init_data(void)
{
	t_tracer_ptr	tracer;

	tracer = (t_tracer_ptr)ft_malloc(sizeof(t_tracer));
	tracer->fd = 0;
	tracer->mlx = NULL;
	tracer->img = NULL;
	tracer->scene = init_scene();
	return (tracer);
}
