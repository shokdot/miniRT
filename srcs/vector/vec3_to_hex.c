/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:04:55 by tigran            #+#    #+#             */
/*   Updated: 2025/03/01 14:15:45 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	vec3_to_hex(t_vec3 color, double intensity)
{
	int	r;
	int	g;
	int	b;

	r = ((int)color.x & 0xFF) * intensity;
	g = ((int)color.y & 0xFF) * intensity;
	b = ((int)color.z & 0xFF) * intensity;
	return ((r << 16) | (g << 8) | b);
}
