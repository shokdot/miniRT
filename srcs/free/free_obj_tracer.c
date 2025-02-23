/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj_tracer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:03:57 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 13:01:11 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_obj_tracer(t_tracer_ptr tracer)
{
	free_objs(tracer->scene);
	free_figures(tracer->scene->figures);
	clear_lt(&(tracer->scene->figures));
	ft_free((void **)&tracer->scene);
	ft_free((void **)&tracer);
}
