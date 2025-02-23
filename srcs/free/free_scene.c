/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:08:02 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 14:10:32 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_scene(t_scene_ptr scene)
{
	if (!scene)
		return ;
	free_objs(scene);
	free_figures(scene->figures);
	clear_lt(&(scene->figures));
	ft_free((void **)&scene);
}
