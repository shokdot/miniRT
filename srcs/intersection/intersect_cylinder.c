/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:04:18 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/09 14:41:52 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static double	check_height(t_ray ray, t_cylinder_ptr cyl, double t)
{
	t_vec3	p;
	t_vec3	cp;
	double	proj;

	if (t <= EPSILION)
		return (-1);
	p = vec3_add(*(ray.origin), vec3_scale(*(ray.direction), t));
	cp = vec3_sub(p, *(cyl->cords));
	proj = vec3_dot(cp, vec3_norm(*(cyl->norm)));
	if (fabs(proj) <= cyl->height / 2.0)
		return (t);
	return (-1);
}

static double	compute_side_intersection(t_ray ray, t_cylinder_ptr cyl)
{
	t_args2	args;

	args = init_args2(ray, cyl);
	if (args.sqrt_disc < 0)
		return (-1);
	args.t1 = (-args.b - args.sqrt_disc) / (2.0 * args.a);
	args.t2 = (-args.b + args.sqrt_disc) / (2.0 * args.a);
	args.t_candidate = -1;
	args.check1 = check_height(ray, cyl, args.t1);
	args.check2 = check_height(ray, cyl, args.t2);
	if (args.check1 > EPSILION && args.check2 > EPSILION)
		args.t_candidate = fmin(args.check1, args.check2);
	else if (args.check1 > EPSILION)
		args.t_candidate = args.check1;
	else if (args.check2 > EPSILION)
		args.t_candidate = args.check2;
	return (args.t_candidate);
}

static double	intersect_cap(t_ray ray, t_cylinder_ptr cyl, int top)
{
	t_args1	args;

	args.o = *(ray.origin);
	args.d = *(ray.direction);
	args.c = *(cyl->cords);
	args.v = vec3_norm(*(cyl->norm));
	args.r = cyl->diameter / 2.0;
	args.h_half = cyl->height / 2.0;
	if (top)
		args.cap_center = vec3_add(args.c, vec3_scale(args.v, args.h_half));
	else
		args.cap_center = vec3_add(args.c, vec3_scale(args.v, -args.h_half));
	args.ddotv = vec3_dot(args.d, args.v);
	if (fabs(args.ddotv) < EPSILION)
		return (-1);
	args.t = vec3_dot(vec3_sub(args.cap_center, args.o), args.v) / args.ddotv;
	if (args.t <= EPSILION)
		return (-1);
	args.p = vec3_add(args.o, vec3_scale(args.d, args.t));
	if (vec3_len(vec3_sub(args.p, args.cap_center)) <= args.r)
		return (args.t);
	return (-1);
}

static double	compute_cap_intersection(t_ray ray, t_cylinder_ptr cyl)
{
	double	t_top;
	double	t_bottom;

	t_top = intersect_cap(ray, cyl, 1);
	t_bottom = intersect_cap(ray, cyl, 0);
	if (t_top > EPSILION && t_bottom > EPSILION)
		return (fmin(t_top, t_bottom));
	else if (t_top > EPSILION)
		return (t_top);
	else if (t_bottom > EPSILION)
		return (t_bottom);
	return (-1);
}

double	intersect_cylinder(t_ray ray, t_cylinder_ptr cyl)
{
	double	t_side;
	double	t_cap;

	t_side = compute_side_intersection(ray, cyl);
	t_cap = compute_cap_intersection(ray, cyl);
	if (t_side > EPSILION && t_cap > EPSILION)
		return (fmin(t_side, t_cap));
	else if (t_side > EPSILION)
		return (t_side);
	else if (t_cap > EPSILION)
		return (t_cap);
	else
		return (-1);
}
