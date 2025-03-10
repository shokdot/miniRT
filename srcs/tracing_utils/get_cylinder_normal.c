/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:14:06 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/09 14:37:02 by tyavroya         ###   ########.fr       */
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

	cp = vec3_sub(hit_point, *((t_cylinder_ptr)obj)->cords);
	norm_cylinder = vec3_norm(*(((t_cylinder_ptr)obj)->norm));
	proj = vec3_dot(cp, norm_cylinder);
	axis_point = vec3_add(*(((t_cylinder_ptr)obj)->cords),
			vec3_scale(norm_cylinder, proj));
	lateral_normal = vec3_norm(vec3_sub(hit_point, axis_point));
	if (fabs(proj) >= ((t_cylinder_ptr)obj)->height / 2.0 - EPSILION)
	{
		if (proj > 0)
			return (norm_cylinder);
		else
			return (vec3_negate(norm_cylinder));
	}
	return (lateral_normal);
}
