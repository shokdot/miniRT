/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sphere_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:04:02 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 11:16:30 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fill_sphere_struct(char **line, t_tracer_ptr tracer)
{
	t_sphere_ptr	obj;

	obj = (t_sphere_ptr)ft_malloc(sizeof(t_sphere));
	obj->cords = init_vec3(line[1]);
	obj->diameter = ft_atof(line[2]);
	obj->color = init_vec3(line[3]);
	push_back_mv_lt(tracer->scene->figures, obj, SPHERE);
}
