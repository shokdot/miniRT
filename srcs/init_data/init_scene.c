/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:08:40 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 17:08:28 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_scene_ptr	init_scene(void)
{
	t_scene_ptr	scene;

	scene = (t_scene_ptr)ft_malloc(sizeof(t_scene));
	scene->ambient = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->vcam = NULL;
	scene->vplane = NULL;
	scene->figures = init_lt();
	scene->amb_count = 0;
	scene->cam_count = 0;
	scene->lgt_count = 0;
	return (scene);
}
