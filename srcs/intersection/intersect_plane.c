/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:57:34 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/04 17:58:25 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	intersect_plane(t_ray ray, t_plane_ptr plane)
{
	double	denom;
	t_vec3	diff;
	double	t;

	denom = vec3_dot(*(ray.direction), *(plane->norm));
	if (fabs(denom) < EPSILION)
		return (-1);
	diff = vec3_sub(*(plane->cords), *(ray.origin));
	t = vec3_dot(diff, *(plane->norm)) / denom;
	if (t >= 0)
		return (t);
	return (-1);
}
