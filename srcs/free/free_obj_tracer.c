/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj_tracer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:03:57 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 16:06:03 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_obj_tracer(t_tracer_ptr tracer)
{
	free_scene(tracer->scene);
	ft_free((void **)&tracer);
}
