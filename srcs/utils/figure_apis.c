/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_apis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:47:38 by tigran            #+#    #+#             */
/*   Updated: 2025/02/27 21:53:26 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double intersect_api(t_node_ptr figure, t_ray ray)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == SPHERE)
		return intersect_sphere(ray, ((t_sphere_ptr)obj));
	else if (figure->obj_type == PLANE)
		return intersect_plane(ray, ((t_plane_ptr)obj));
	else if (figure->obj_type == CYLINDER)
		return intersect_cylinder(ray, ((t_cylinder_ptr)obj));
	ft_err("Error in intersect_api", EXIT_FAILURE);
	return (0);
}

t_vec3	get_color(t_node_ptr figure)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == CYLINDER)
		return *(((t_cylinder_ptr)obj)->color);
	else if (figure->obj_type == PLANE)
		return *(((t_plane_ptr)obj)->color);
	else if (figure->obj_type == SPHERE)
		return *(((t_sphere_ptr)obj)->color);
	ft_err("Error in get_color", EXIT_FAILURE);
	return ((t_vec3){0,0,0});
}


t_vec3	get_cords(t_node_ptr figure)
{
	void	*obj;

	obj = figure->data;
	if (figure->obj_type == CYLINDER)
		return *(((t_cylinder_ptr)obj)->cords);
	else if (figure->obj_type == PLANE)
		return *(((t_plane_ptr)obj)->cords);
	else if (figure->obj_type == SPHERE)
		return *(((t_sphere_ptr)obj)->cords);
	ft_err("Error in get_cords", EXIT_FAILURE);
	return ((t_vec3){0,0,0});
}

t_vec3 get_normal(t_node_ptr node, t_vec3 hit_point)
{
	void*	obj;

	obj = node->data;
    if (node->obj_type == SPHERE)
        return vec3_norm(vec3_sub(hit_point, *((t_sphere_ptr)obj)->cords));
    else if (node->obj_type == PLANE)
        return *((t_plane_ptr)obj)->norm;
    else if (node->obj_type == CYLINDER)
    {
        t_vec3 cp = vec3_sub(hit_point, *((t_cylinder_ptr)obj)->cords);
        
        // Project cp onto the cylinder's axis (norm)
        double proj = vec3_dot(cp, *(((t_cylinder_ptr)obj)->norm));
        
        // Determine the point on the axis closest to the hit point.
        t_vec3 axis_point = vec3_add(*(((t_cylinder_ptr)obj)->cords), vec3_scale(*(((t_cylinder_ptr)obj)->norm), proj));
        
        // For the lateral surface, the normal is the direction from the axis to the hit point.
        t_vec3 lateral_normal = vec3_norm(vec3_sub(hit_point, axis_point));
        
        // Optional: if the hit is on one of the caps (top or bottom), return the cap normal.
        // A small tolerance (e.g., 0.001) is used to decide if the hit point is on a cap.
        double half_height = ((t_cylinder_ptr)obj)->height / 2.0;
        if (fabs(proj) >= half_height - 0.001)
        {
            // If hit on the top cap, the normal is the same as the cylinder axis.
            // If on the bottom cap, it is the negative of the cylinder axis.
            if (proj > 0)
                return *(((t_cylinder_ptr)obj)->norm);
            else
                return vec3_negate(*(((t_cylinder_ptr)obj)->norm));
        }
        
        return lateral_normal;
    }
    // Default return value (e.g. if the object type is unrecognized)
    return (t_vec3){0, 0, 0};
}