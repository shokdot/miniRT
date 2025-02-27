/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:32:26 by tigran            #+#    #+#             */
/*   Updated: 2025/02/27 23:20:43 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_ray_ptr	init_ray(void)
{
	t_ray_ptr	res;

	res = (t_ray_ptr)malloc(sizeof(t_ray));
	res = (t_ray_ptr)ft_malloc(sizeof(t_ray));
	return (res);
}
