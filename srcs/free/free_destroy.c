/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:13:58 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 17:53:41 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_destroy(t_tracer_ptr tracer)
{
	free_lib(tracer);
	free_obj_tracer(tracer);
	exit(EXIT_SUCCESS);
}
