/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:04:18 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/01 16:13:19 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static double	check_height(t_ray ray, t_cylinder_ptr cylinder, double t)
{
	double	y;
	double	ymin;
	double	ymax;

	if (t <= 0)
		return (-1);
	y = ray.origin->y + t * ray.direction->y;
	ymin = cylinder->cords->y - cylinder->height / 2.0;
	ymax = cylinder->cords->y + cylinder->height / 2.0;
	if (y >= ymin && y <= ymax)
		return (t);
	return (-1);
}

static double	intersect_cap(t_ray ray, t_cylinder_ptr cylinder, double y_cap)
{
	t_vec3	o;
	t_vec3	d;
	t_vec3	c;
	double	t;
	t_vec3	p;
	double	dist;

	o = *(ray.origin);
	d = *(ray.direction);
	c = *(cylinder->cords);
	if (fabs(d.y) < 1e-6)
		return (-1);
	t = (y_cap - o.y) / d.y;
	p = vec3_add(o, vec3_scale(d, t));
	dist = pow(p.x - c.x, 2) + pow(p.z - c.z, 2);
	if (t > 0 && dist <= pow(cylinder->diameter / 2.0, 2))
		return (t);
	return (-1);
}

static double	compute_side_intersection(t_ray ray, t_cylinder_ptr cylinder)
{
	double	t;

	t_vec3 o, d, c;
	double a, b, c_term, sqrt_disc, t1, t2;
	o = *(ray.origin);
	d = *(ray.direction);
	c = *(cylinder->cords);
	a = d.x * d.x + d.z * d.z;
	b = 2.0 * ((o.x - c.x) * d.x + (o.z - c.z) * d.z);
	c_term = (o.x - c.x) * (o.x - c.x) + (o.z - c.z) * (o.z - c.z)
		- pow(cylinder->diameter / 2.0, 2);
	sqrt_disc = calculate_discriminant(a, b, c_term);
	if (sqrt_disc < 0)
		return (-1);
	t1 = (-b - sqrt_disc) / (2 * a);
	t2 = (-b + sqrt_disc) / (2 * a);
	t = check_height(ray, cylinder, t1);
	if (t > 0)
		return (t);
	t = check_height(ray, cylinder, t2);
	if (t > 0)
		return (t);
	return (-1);
}

static double	compute_cap_intersection(t_ray ray, t_cylinder_ptr cylinder,
		double ymin, double ymax)
{
	double	t_bottom;
	double	t_top;

	t_bottom = intersect_cap(ray, cylinder, ymin);
	t_top = intersect_cap(ray, cylinder, ymax);
	if (t_bottom > 0 && t_top > 0)
		return (fmin(t_bottom, t_top));
	else if (t_bottom > 0)
		return (t_bottom);
	else if (t_top > 0)
		return (t_top);
	else
		return (-1);
}

double	intersect_cylinder(t_ray ray, t_cylinder_ptr cylinder)
{
	t_vec3	c;
	double	ymin;
	double	ymax;
	double	t_side;
	double	t_caps;

	c = *(cylinder->cords);
	ymin = c.y - (cylinder->height / 2.0);
	ymax = c.y + (cylinder->height / 2.0);
	t_side = compute_side_intersection(ray, cylinder);
	t_caps = compute_cap_intersection(ray, cylinder, ymin, ymax);
	if (t_side > 0 && t_caps > 0)
		return (fmin(t_side, t_caps));
	if (t_side > 0)
		return (t_side);
	return (t_caps);
}
