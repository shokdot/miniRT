/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_light_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:04:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 11:16:46 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fill_light_struct(char **line, t_tracer_ptr tracer)
{
	t_light_ptr	obj;

	obj = (t_light_ptr)ft_malloc(sizeof(t_light));
	obj->cords = init_vec3(line[1]);
	obj->ratio = ft_atof(line[2]);
	tracer->scene->light = obj;
}
