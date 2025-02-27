/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_reflect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:50:43 by tigran            #+#    #+#             */
/*   Updated: 2025/02/27 17:50:53 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	vec3_reflect(t_vec3 v, t_vec3 n)
{
    double dot_product = vec3_dot(v, n);
    return vec3_sub(v, vec3_scale(n, 2 * dot_product));
}
