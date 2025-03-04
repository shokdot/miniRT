/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:08:38 by tigran            #+#    #+#             */
/*   Updated: 2025/03/04 18:44:15 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_vec3	calculate_cofficent(t_ray ray, t_sphere_ptr sphere)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = vec3_sub(*(ray.origin), *(sphere->cords));
	a = vec3_dot(*(ray.direction), *(ray.direction));
	b = 2.0 * vec3_dot(*(ray.direction), oc);
	c = vec3_dot(oc, oc) - sphere->diameter;
	return ((t_vec3){a, b, c});
}

double	intersect_sphere(t_ray ray, t_sphere_ptr sphere)
{
	double	discriminant;
	double	t1;
	double	t2;
	t_vec3	cofficent;

	cofficent = calculate_cofficent(ray, sphere);
	discriminant = calculate_discriminant(cofficent.x, cofficent.y,
			cofficent.z);
	if (discriminant < 0)
		return (-1);
	t1 = (-cofficent.y - discriminant) / (2 * cofficent.x);
	t2 = (-cofficent.y + discriminant) / (2 * cofficent.x);
	if (t1 > 0 && t2 > 0)
		return (fmin(t1, t2));
	else if (t1 > 0)
		return (t1);
	else if (t2 > 0)
		return (t2);
	else
		return (-1);
}
