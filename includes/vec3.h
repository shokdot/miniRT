/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:51:42 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/27 21:54:37 by tigran           ###   ########.fr       */
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

void					vec3_print(t_vec3 a);
double					vec3_len(t_vec3 v);
double					vec3_dot(t_vec3 v1, t_vec3 v2);
double					vec3_dot_num(t_vec3 v, double f);
t_vec3					vec3_add(t_vec3 a, t_vec3 b);
t_vec3					vec3_add_num(t_vec3 a, double f);
t_vec3					vec3_cross(t_vec3 a, t_vec3 b);
t_vec3					vec3_norm(t_vec3 v);
t_vec3					vec3_sub(t_vec3 a, t_vec3 b);
t_vec3					vec3_scale(t_vec3 v, double scalar);
t_vec3					vec3_reflect(t_vec3 v, t_vec3 n);
t_vec3					vec3_negate(t_vec3 v);


#endif
