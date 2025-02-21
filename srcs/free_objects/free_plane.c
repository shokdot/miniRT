/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:32:42 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/21 12:52:29 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_plane(t_plane_ptr obj)
{
	free(obj->cords);
	free(obj->norm);
	free(obj->color);
}
