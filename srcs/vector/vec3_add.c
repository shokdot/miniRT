/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:53:31 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/28 14:36:44 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	res = (t_vec3){a.x + b.x, a.y + b.y, a.z + b.z};
	return (res);
}

t_vec3	vec3_add_num(t_vec3 a, double f)
{
	t_vec3	res;

	res = (t_vec3){a.x + f, a.y + f, a.z + f};
	return (res);
}
