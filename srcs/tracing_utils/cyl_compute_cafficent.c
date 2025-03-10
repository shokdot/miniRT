/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_compute_cafficent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:46:39 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 11:58:15 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	cyl_compute_cofficent(t_ray ray, t_cylinder_ptr cyl)
{
	t_vec3	cofficent;
	double	co_dot_v;
	double	r;
	t_vec3	d_perp;
	t_vec3	co_perp;

	co_dot_v = vec3_dot(vec3_sub(*(ray.origin), *(cyl->cords)),
			vec3_norm(*(cyl->norm)));
	d_perp = vec3_sub(*(ray.direction), vec3_scale(vec3_norm(*(cyl->norm)),
				vec3_dot(*(ray.direction), vec3_norm(*(cyl->norm)))));
	co_perp = vec3_sub(vec3_sub(*(ray.origin), *(cyl->cords)),
			vec3_scale(vec3_norm(*(cyl->norm)), co_dot_v));
	r = cyl->diameter / 2.0;
	cofficent.x = vec3_dot(d_perp, d_perp);
	cofficent.y = 2.0 * vec3_dot(d_perp, co_perp);
	cofficent.z = vec3_dot(co_perp, co_perp) - r * r;
	return (cofficent);
}
