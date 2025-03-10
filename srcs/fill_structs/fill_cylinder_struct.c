/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cylinder_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:49:42 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/03 18:28:32 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fill_cylinder_struct(char **line, t_tracer_ptr tracer)
{
	t_cylinder_ptr	obj;

	obj = (t_cylinder_ptr)ft_malloc(sizeof(t_cylinder));
	obj->cords = init_vec3(line[1]);
	obj->norm = init_vec3(line[2]);
	obj->diameter = ft_atof(line[3]);
	obj->height = ft_atof(line[4]);
	obj->color = init_vec3(line[5]);
	push_back_mv_lt(tracer->scene->figures, obj, CYLINDER);
}
