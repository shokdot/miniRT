/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:38:01 by tigran            #+#    #+#             */
/*   Updated: 2025/02/26 19:59:34 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	calculate(t_ray ray, float t)
{
	t_vec3	res;

	res = vec3_add_num(*(ray.origin), vec3_dot_num(*(ray.direction), t)); // origin + direction * t (p + dt)
	return (res);
}