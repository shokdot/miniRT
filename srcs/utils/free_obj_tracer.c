/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj_tracer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:03:57 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/21 13:04:25 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_obj_tracer(t_tracer_ptr tracer)
{
	free_objs(tracer->figures);
	clear_lt(&(tracer->figures));
	ft_free((void **)&tracer);
}
