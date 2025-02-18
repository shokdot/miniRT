/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:34:21 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/18 22:34:29 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_vec3_ptr	init_vec3(char *line)
{
	char		**splited;
	t_vec3_ptr	vec;

	splited = ft_split(line, ',');
	vec = (t_vec3_ptr)ft_malloc(sizeof(t_vec3));
	vec->x = ft_atof(splited[0]);
	vec->y = ft_atof(splited[1]);
	vec->z = ft_atof(splited[2]);
	return (vec);
}
