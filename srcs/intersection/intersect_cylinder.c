/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:04:18 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/09 22:14:27 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <miniRT.h>
#include <stdio.h>
#include <stdlib.h>

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

static double	compute_side_intersection(t_ray ray, t_cylinder_ptr cyl)
{
	t_vec3	O;
	t_vec3	D;
	t_vec3	C;
	t_vec3	V;
	t_vec3	CO;
	double	DdotV;
	double	COdotV;
	t_vec3	D_perp;
	t_vec3	CO_perp;
	double	A;
	double	B;
	double	C_val;
	double	sqrt_disc;
	double	t1;
	double	t2;
	double	r;
	double	t_candidate;
	double	check1;
	double	check2;

	O = *(ray.origin);
	D = *(ray.direction);
	C = *(cyl->cords);
	V = vec3_norm(*(cyl->norm));
	CO = vec3_sub(O, C);
	r = cyl->diameter / 2.0;
	DdotV = vec3_dot(D, V);
	COdotV = vec3_dot(CO, V);
	D_perp = vec3_sub(D, vec3_scale(V, DdotV));
	CO_perp = vec3_sub(CO, vec3_scale(V, COdotV));
	A = vec3_dot(D_perp, D_perp);
	B = 2.0 * vec3_dot(D_perp, CO_perp);
	C_val = vec3_dot(CO_perp, CO_perp) - r * r;
	sqrt_disc = calculate_discriminant(A, B, C_val);
	if (sqrt_disc < 0)
		return (-1);
	t1 = (-B - sqrt_disc) / (2.0 * A);
	t2 = (-B + sqrt_disc) / (2.0 * A);
	t_candidate = -1;
	check1 = check_height(ray, cyl, t1);
	check2 = check_height(ray, cyl, t2);
	if (check1 > EPSILION && check2 > EPSILION)
		t_candidate = (check1 < check2) ? check1 : check2;
	else if (check1 > EPSILION)
		t_candidate = check1;
	else if (check2 > EPSILION)
		t_candidate = check2;
	return (t_candidate);
}

static double	intersect_cap(t_ray ray, t_cylinder_ptr cyl, int top)
{
	t_vec3	O;
	t_vec3	D;
	t_vec3	C;
	t_vec3	V;
	double	r;
	double	h_half;
	t_vec3	cap_center;
	double	DdotV;
	double	t;
	t_vec3	P;

	O = *(ray.origin);
	D = *(ray.direction);
	C = *(cyl->cords);
	V = vec3_norm(*(cyl->norm));
	r = cyl->diameter / 2.0;
	h_half = cyl->height / 2.0;
	if (top)
		cap_center = vec3_add(C, vec3_scale(V, h_half));
	else
		cap_center = vec3_add(C, vec3_scale(V, -h_half));
	DdotV = vec3_dot(D, V);
	if (fabs(DdotV) < EPSILION)
		return (-1);
	t = vec3_dot(vec3_sub(cap_center, O), V) / DdotV;
	if (t <= EPSILION)
		return (-1);
	P = vec3_add(O, vec3_scale(D, t));
	if (vec3_len(vec3_sub(P, cap_center)) <= r)
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
