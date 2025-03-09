/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:14:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/09 22:03:31 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	get_cylinder_normal(t_cylinder_ptr obj, t_vec3 hit_point)
{
	t_vec3	cp;
	double	proj;
	t_vec3	axis_point;
	t_vec3	lateral_normal;
	t_vec3	norm_cylinder;

	cp = vec3_sub(hit_point, *(obj->cords));
	norm_cylinder = vec3_norm(*(obj->norm));
	proj = vec3_dot(cp, norm_cylinder);
	axis_point = vec3_add(*(obj->cords), vec3_scale(norm_cylinder, proj));
	lateral_normal = vec3_norm(vec3_sub(hit_point, axis_point));
	if (fabs(proj) >= (obj->height / 2.0) - EPSILION)
	{
		if (proj > 0)
			return (norm_cylinder);
		return (vec3_negate(norm_cylinder));
	}
	return (lateral_normal);
}
