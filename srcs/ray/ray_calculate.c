/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:38:01 by tyavroya          #+#    #+#             */
/*   Updated: 2025/02/27 13:55:22 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	calculate(t_ray ray, float t)
{
	t_vec3	res;

	res = vec3_add_num(*(ray.origin), vec3_dot_num(*(ray.direction), t));
	return (res);
}
