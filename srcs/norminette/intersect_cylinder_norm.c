/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_norm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:30:55 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/09 14:43:11 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_args2	init_args2(t_ray ray, t_cylinder_ptr cyl)
{
	t_args2	args;

	args.o = *(ray.origin);
	args.d = *(ray.direction);
	args.c = *(cyl->cords);
	args.v = vec3_norm(*(cyl->norm));
	args.co = vec3_sub(args.o, args.c);
	args.r = cyl->diameter / 2.0;
	args.ddotv = vec3_dot(args.d, args.v);
	args.codotv = vec3_dot(args.co, args.v);
	args.d_perp = vec3_sub(args.d, vec3_scale(args.v, args.ddotv));
	args.co_perp = vec3_sub(args.co, vec3_scale(args.v, args.codotv));
	args.a = vec3_dot(args.d_perp, args.d_perp);
	args.b = 2.0 * vec3_dot(args.d_perp, args.co_perp);
	args.c_val = vec3_dot(args.co_perp, args.co_perp) - args.r * args.r;
	args.sqrt_disc = calculate_discriminant(args.a, args.b, args.c_val);
	return (args);
}
