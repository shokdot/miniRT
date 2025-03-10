/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:04:14 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 18:06:01 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_ray(t_ray_ptr ray)
{
	if (!ray)
		return ;
	ft_free((void **)&ray->direction);
	ft_free((void **)&ray->origin);
	ft_free((void **)&ray);
}
