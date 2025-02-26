/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d_to_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:04:55 by tigran            #+#    #+#             */
/*   Updated: 2025/02/26 22:05:03 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int vec3_to_hex(t_vec3 color)
{
    int r = (int)color.x & 0xFF; // Clamp to 0-255
    int g = (int)color.y & 0xFF;
    int b = (int)color.z & 0xFF;
    return (r << 16) | (g << 8) | b; // Combine into 0xRRGGBB
}