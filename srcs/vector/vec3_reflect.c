/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_reflect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:50:43 by tigran            #+#    #+#             */
/*   Updated: 2025/02/28 14:36:10 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	vec3_reflect(t_vec3 v, t_vec3 n)
{
	double	dot_product;

	dot_product = vec3_dot(v, n);
	return (vec3_sub(v, vec3_scale(n, 2 * dot_product)));
}
