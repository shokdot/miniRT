/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:30:06 by tigran            #+#    #+#             */
/*   Updated: 2025/02/27 23:20:12 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <vec3.h>

typedef struct s_ray	t_ray;
typedef t_ray			*t_ray_ptr;

struct					s_ray
{
	t_vec3_ptr			origin;
	t_vec3_ptr			direction;
};

t_vec3					calculate(t_ray ray, float t);

#endif // RAY_H
