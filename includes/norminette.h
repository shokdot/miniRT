/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:28:30 by tyavroya          #+#    #+#             */
/*   Updated: 2025/03/09 14:39:58 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMINETTE_H
# define NORMINETTE_H

# include <figures.h>
# include <ray.h>
# include <vec3.h>

typedef struct s_args1
{
	t_vec3	o;
	t_vec3	d;
	t_vec3	c;
	t_vec3	v;
	double	r;
	double	h_half;
	t_vec3	cap_center;
	double	ddotv;
	double	t;
	t_vec3	p;
}			t_args1;

typedef struct s_args2
{
	t_vec3	o;
	t_vec3	d;
	t_vec3	c;
	t_vec3	v;
	t_vec3	co;
	double	ddotv;
	double	codotv;
	t_vec3	d_perp;
	t_vec3	co_perp;
	double	a;
	double	b;
	double	c_val;
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