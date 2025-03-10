/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_side_candidate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:52:40 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 11:57:40 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static double	check_height(t_ray ray, t_cylinder_ptr cylinder, double t)
{
	t_vec3	p;
	t_vec3	cp;
	double	proj;

	if (t <= EPSILION)
		return (-1);
	p = vec3_add(*(ray.origin), vec3_scale(*(ray.direction), t));
	cp = vec3_sub(p, *(cylinder->cords));
	proj = vec3_dot(cp, vec3_norm(*(cylinder->norm)));
	if (fabs(proj) <= cylinder->height / 2.0)
		return (t);
	return (-1);
}

double	compute_side_candidate(t_ray ray, t_cylinder_ptr cyl, double t1,
		double t2)
{
	double	check1;
	double	check2;

	check1 = check_height(ray, cyl, t1);
	check2 = check_height(ray, cyl, t2);
	if (check1 > EPSILION && check2 > EPSILION)
		return (fmin(check1, check2));
	else if (check1 > EPSILION)
		return (check1);
	else if (check2 > EPSILION)
		return (check2);
	return (-1);
}
