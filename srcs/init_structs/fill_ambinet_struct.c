/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ambinet_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:21:08 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 11:15:46 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fill_ambient_struct(char **line, t_tracer_ptr tracer)
{
	t_ambient_ptr	obj;

	obj = (t_ambient_ptr)ft_malloc(sizeof(t_ambient));
	obj->ratio = ft_atof(line[1]);
	obj->color = init_vec3(line[2]);
	tracer->scene->ambient = obj;
}
