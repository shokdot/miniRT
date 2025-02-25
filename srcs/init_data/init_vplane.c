/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vplane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:04:49 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/25 17:19:42 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	init_vplane(t_tracer_ptr tracer)
{
	double	aspect_ratio;

	tracer->scene->vplane = (t_vplane_ptr)ft_malloc(sizeof(t_vplane));
	tracer->scene->vplane->height = 2.0 * tan(tracer->scene->camera->fov * 0.5
			* M_PI / 180.0);
	aspect_ratio = (double)WIDTH / HEIGHT;
	tracer->scene->vplane->width = tracer->scene->vplane->height * aspect_ratio;
	tracer->scene->vplane->pixel_dx = tracer->scene->vplane->width / WIDTH;
	tracer->scene->vplane->pixel_dy = tracer->scene->vplane->height / HEIGHT;
}
