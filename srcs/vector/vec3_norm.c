/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:29:19 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/26 18:15:43 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	vec3_norm(t_vec3 v)
{
	float	len;
	t_vec3	res;

	len = vec3_len(v);
	res = (t_vec3){v.x / len, v.y / len, v.z / len};
	return (res);
}
