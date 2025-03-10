/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cap_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:00:45 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 11:18:32 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	calc_cap_center(t_cylinder_ptr cylinder, int top)
{
	t_vec3	cords;
	t_vec3	norm;
	t_vec3	cap_center;

	cords = *(cylinder->cords);
	norm = vec3_norm(*(cylinder->norm));
	if (top)
		return (cap_center = vec3_add(cords, vec3_scale(norm, cylinder->height
					/ 2.0)));
	return (cap_center = vec3_add(cords, vec3_scale(norm, -(cylinder->height
					/ 2.0))));
}
