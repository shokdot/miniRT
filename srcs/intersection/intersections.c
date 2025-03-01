/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:08:38 by tigran            #+#    #+#             */
/*   Updated: 2025/03/01 16:09:10 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	intersect_sphere(t_ray ray, t_sphere_ptr sphere)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	sqrt_discriminant;
	double	t1;
	double	t2;

	oc = vec3_sub(*(ray.origin), *(sphere->cords));
	a = vec3_dot(*(ray.direction), *(ray.direction));
	b = 2.0 * vec3_dot(*(ray.direction), oc);
	c = vec3_dot(oc, oc) - sphere->diameter;
	sqrt_discriminant = calculate_discriminant(a, b, c);
	if (sqrt_discriminant < 0)
		return (-1);
	t1 = (-b - sqrt_discriminant) / (2 * a);
	t2 = (-b + sqrt_discriminant) / (2 * a);
	if (t1 > 0 && t2 > 0)
		return (fmax(t1, t2));
	else if (t1 > 0)
		return (t1);
	else if (t2 > 0)
		return (t2);
	else
		return (-1);
}

double	intersect_plane(t_ray ray, t_plane_ptr plane)
{
	double	denom;
	t_vec3	diff;
	double	t;

	denom = vec3_dot(*(ray.direction), *(plane->norm));
	// Check if the ray is parallel to the plane
	if (fabs(denom) < 1e-6)
		return (-1); // No intersection (or the ray lies in the plane)
	diff = vec3_sub(*(plane->cords), *(ray.origin));
	t = vec3_dot(diff, *(plane->norm)) / denom;
	return ((t >= 0) ? t : -1);
}
