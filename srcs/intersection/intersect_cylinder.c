/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:04:18 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/10 11:56:35 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static double	compute_side_intersection(t_ray ray, t_cylinder_ptr cyl)
{
	double	sqrt_disc;
	double	t1;
	double	t2;
	t_vec3	cofficent;

	cofficent = cyl_compute_cofficent(ray, cyl);
	sqrt_disc = calculate_discriminant(cofficent.x, cofficent.y, cofficent.z);
	if (sqrt_disc < 0)
		return (-1);
	t1 = (-cofficent.y - sqrt_disc) / (2.0 * cofficent.x);
	t2 = (-cofficent.y + sqrt_disc) / (2.0 * cofficent.x);
	return (compute_side_candidate(ray, cyl, t1, t2));
}

static double	intersect_cap(t_ray ray, t_cylinder_ptr cyl, int top)
{
	t_vec3	cap_center;
	double	dot_v;
	double	t;
	t_vec3	p;

	cap_center = calc_cap_center(cyl, top);
	dot_v = vec3_dot(*(ray.direction), vec3_norm(*(cyl->norm)));
	if (fabs(dot_v) < EPSILION)
		return (-1);
	t = vec3_dot(vec3_sub(cap_center, *(ray.origin)), vec3_norm(*(cyl->norm)))
		/ dot_v;
	if (t <= EPSILION)
		return (-1);
	p = vec3_add(*(ray.origin), vec3_scale(*(ray.direction), t));
	if (vec3_len(vec3_sub(p, cap_center)) <= cyl->diameter / 2.0)
		return (t);
	return (-1);
}

static double	compute_cap_intersection(t_ray ray, t_cylinder_ptr cylinder)
{
	double	t_top;
	double	t_bottom;

	t_top = intersect_cap(ray, cylinder, 1);
	t_bottom = intersect_cap(ray, cylinder, 0);
	if (t_top > EPSILION && t_bottom > EPSILION)
		return (fmin(t_top, t_bottom));
	else if (t_top > EPSILION)
		return (t_top);
	else if (t_bottom > EPSILION)
		return (t_bottom);
	return (-1);
}

double	intersect_cylinder(t_ray ray, t_cylinder_ptr cylinder)
{
	double	t_side;
	double	t_cap;

	t_side = compute_side_intersection(ray, cylinder);
	t_cap = compute_cap_intersection(ray, cylinder);
	if (t_side > EPSILION && t_cap > EPSILION)
		return (fmin(t_side, t_cap));
	else if (t_side > EPSILION)
		return (t_side);
	else if (t_cap > EPSILION)
		return (t_cap);
	else
		return (-1);
}
