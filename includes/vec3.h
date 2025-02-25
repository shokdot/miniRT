/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:51:42 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/25 16:36:51 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3	t_vec3;
typedef t_vec3			*t_vec3_ptr;

struct					s_vec3
{
	double				x;
	double				y;
	double				z;
};

double					vec3_dot(t_vec3 v1, t_vec3 v2);

#endif
