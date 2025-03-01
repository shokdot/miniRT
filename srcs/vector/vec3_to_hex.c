/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:04:55 by tigran            #+#    #+#             */
/*   Updated: 2025/03/01 18:58:03 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	vec3_to_hex(t_vec3 color, double intensity)
{
	int	r;
	int	g;
	int	b;

	r = ((int)(color.x * intensity) & 0xFF);
	g = ((int)(color.y * intensity) & 0xFF);
	b = ((int)(color.z * intensity) & 0xFF);
	return ((r << 16) | (g << 8) | b);
}
