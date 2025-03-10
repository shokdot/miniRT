/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_discriminant.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:05:36 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/09 14:22:39 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

double	calculate_discriminant(double a, double b, double c_term)
{
	double	discriminant;

	discriminant = b * b - 4 * a * c_term;
	if (discriminant < 0)
		return (-1);
	return (sqrt(discriminant));
}
