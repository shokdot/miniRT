/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:04:55 by tigran            #+#    #+#             */
/*   Updated: 2025/02/28 14:34:01 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	vec3_to_hex(t_vec3 color)
{
	int	r;
	int	g;
	int	b;

	r = (int)color.x & 0xFF;
	g = (int)color.y & 0xFF;
	b = (int)color.z & 0xFF;
	return ((r << 16) | (g << 8) | b);
}
