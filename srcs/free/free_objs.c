/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:36:51 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 18:01:29 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_objs(t_scene_ptr scene)
{
	free_ambient(scene->ambient);
	free_camera(scene->camera);
	free_light(scene->light);
	ft_free((void **)&scene->vplane);
	ft_free((void **)&scene->vcam);
}
