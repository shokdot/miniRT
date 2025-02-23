/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:34:32 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 13:47:20 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_sphere(t_sphere_ptr obj)
{
	if (!obj)
		return ;
	free(obj->cords);
	free(obj->color);
}
