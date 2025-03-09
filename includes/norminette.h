/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:28:30 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/09 14:31:57 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMINETTE_H
# define NORMINETTE_H

# include <figures.h>
# include <ray.h>
# include <vec3.h>

typedef struct s_args1
{
	t_vec3	O;
	t_vec3	D;
	t_vec3	C;
	t_vec3	V;
	double	r;
	double	h_half;
	t_vec3	cap_center;
	double	DdotV;
	double	t;
	t_vec3	P;
}			t_args1;

typedef struct s_args2
{
	t_vec3	O;
	t_vec3	D;
	t_vec3	C;
	t_vec3	V;
	t_vec3	CO;
	double	DdotV;
	double	COdotV;
	t_vec3	D_perp;
	t_vec3	CO_perp;
	double	A;
	double	B;
	double	C_val;
	double	sqrt_disc;
	double	t1;
	double	t2;
	double	r;
	double	t_candidate;
	double	check1;
	double	check2;
}			t_args2;

t_args2		init_args2(t_ray ray, t_cylinder_ptr cyl);

#endif // NORMINETTE_H