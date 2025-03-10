/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:38:01 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/10 16:51:10 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_ray_ptr	ray_calculate(int x, int y, t_tracer_ptr tracer)
{
	double	ray_x;
	double	ray_y;
	t_vec3	ray_dir;
	t_vec3	cam_cords;

	cam_cords = *(tracer->scene->camera->cords);
	ray_x = (x - WIDTH / 2.0) * tracer->scene->vplane->pixel_dx;
	ray_y = (HEIGHT / 2.0 - y) * tracer->scene->vplane->pixel_dy;
	ray_dir = vec3_norm((t_vec3){tracer->scene->vcam->forward.x + ray_x
			* tracer->scene->vcam->right.x + ray_y * tracer->scene->vcam->up.x,
			tracer->scene->vcam->forward.y + ray_x
			* tracer->scene->vcam->right.y + ray_y * tracer->scene->vcam->up.y,
			tracer->scene->vcam->forward.z + ray_x
			* tracer->scene->vcam->right.z + ray_y
			* tracer->scene->vcam->up.z});
	return (init_ray(cam_cords, ray_dir));
}
