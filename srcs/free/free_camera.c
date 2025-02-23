/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:25:47 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 15:56:55 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_camera(t_camera_ptr obj)
{
	if (!obj)
		return ;
	free(obj->cords);
	free(obj->norm);
	free(obj);
}
