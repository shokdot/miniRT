/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vcam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:29:01 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 16:45:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	init_vcam(t_tracer_ptr tracer)
{
	tracer->scene->vcam = (t_vcam_ptr)ft_malloc(sizeof(t_vcam));
	tracer->scene->vcam->forward = *(tracer->scene->camera->norm);
	tracer->scene->vcam->up_ref = (t_vec3){0, 1, 0};
	tracer->scene->vcam->right = vec3_norm(vec3_cross(tracer->scene->vcam->forward,
				tracer->scene->vcam->up_ref));
	tracer->scene->vcam->up = vec3_norm(vec3_cross(tracer->scene->vcam->right,
				tracer->scene->vcam->forward));
}
