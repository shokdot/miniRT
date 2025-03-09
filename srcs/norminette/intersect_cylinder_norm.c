/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_norm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:30:55 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/09 14:31:05 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_args2	init_args2(t_ray ray, t_cylinder_ptr cyl)
{
	t_args2	args;

	args.O = *(ray.origin);
	args.D = *(ray.direction);
	args.C = *(cyl->cords);
	args.V = vec3_norm(*(cyl->norm));
	args.CO = vec3_sub(args.O, args.C);
	args.r = cyl->diameter / 2.0;
	args.DdotV = vec3_dot(args.D, args.V);
	args.COdotV = vec3_dot(args.CO, args.V);
	args.D_perp = vec3_sub(args.D, vec3_scale(args.V, args.DdotV));
	args.CO_perp = vec3_sub(args.CO, vec3_scale(args.V, args.COdotV));
	args.A = vec3_dot(args.D_perp, args.D_perp);
	args.B = 2.0 * vec3_dot(args.D_perp, args.CO_perp);
	args.C_val = vec3_dot(args.CO_perp, args.CO_perp) - args.r * args.r;
	args.sqrt_disc = calculate_discriminant(args.A, args.B, args.C_val);
	return (args);
}
