/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:27:01 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/23 13:45:48 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_cylinder(t_cylinder_ptr obj)
{
	if (!obj)
		return ;
	free(obj->cords);
	free(obj->norm);
	free(obj->color);
}
