/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:26 by tigran            #+#    #+#             */
/*   Updated: 2025/02/27 23:23:09 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_ray_ptr	init_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray_ptr	res;

	res = (t_ray_ptr)malloc(sizeof(t_ray));
	res->direction = (t_vec3_ptr)malloc(sizeof(t_vec3));
	res->origin = (t_vec3_ptr)malloc(sizeof(t_vec3));
	*(res->direction) = direction;
	*(res->origin) = origin;
	return (res);
}
