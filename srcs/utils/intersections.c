/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:08:38 by tigran            #+#    #+#             */
/*   Updated: 2025/02/27 20:05:22 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double intersect_sphere(t_ray ray, t_sphere_ptr sphere)
{
    t_vec3 oc = vec3_sub(*(ray.origin), *(sphere->cords));

    double a = vec3_dot(*(ray.direction), *(ray.direction));
    double b = 2.0 * vec3_dot(*(ray.direction), oc);
    double c = vec3_dot(oc, oc) - sphere->diameter;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return (-1);

    double sqrt_discriminant = sqrt(discriminant);
    double t1 = (-b - sqrt_discriminant) / (2 * a);
    double t2 = (-b + sqrt_discriminant) / (2 * a);

    if (t1 > 0 && t2 > 0)
	{
		if (t1 < t2)
			return (t2);
		else
			return (t1);
	}
    else if (t1 > 0)
        return (t1);
    else if (t2 > 0)
        return (t2);
    else
        return (-1);
}

double intersect_cylinder(t_ray ray, t_cylinder_ptr cylinder)
{
    t_vec3 o = *(ray.origin);
    t_vec3 d = *(ray.direction);

    double ox = o.x - cylinder->cords->x;
    double oz = o.z - cylinder->cords->z;

    double a = d.x * d.x + d.z * d.z;
    double b = 2.0 * (ox * d.x + oz * d.z);
    double c = ox * ox + oz * oz - cylinder->diameter;

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return -1; // No intersection

    double sqrt_disc = sqrt(discriminant);
    double t1 = (-b - sqrt_disc) / (2 * a);
    double t2 = (-b + sqrt_disc) / (2 * a);

    if (t1 > 0 && t2 > 0)
        return (t1 < t2) ? t1 : t2;
    else if (t1 > 0)
        return t1;
    else if (t2 > 0)
        return t2;
    else
        return -1;
}

double intersect_plane(t_ray ray, t_plane_ptr plane)
{
    double denom = vec3_dot(*(ray.direction), *(plane->norm));
    // Check if the ray is parallel to the plane
    if (fabs(denom) < 1e-6)
        return -1; // No intersection (or the ray lies in the plane)

    t_vec3 diff = vec3_sub(*(plane->cords), *(ray.origin));
    double t = vec3_dot(diff, *(plane->norm)) / denom;
    return (t >= 0) ? t : -1;
}
