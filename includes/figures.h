/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:46:00 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/22 22:54:14 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H

# include <vec3.h>

typedef struct s_sphere		t_sphere;
typedef t_sphere			*t_sphere_ptr;

typedef struct s_plane		t_plane;
typedef t_plane				*t_plane_ptr;

typedef struct s_cylinder	t_cylinder;
typedef t_cylinder			*t_cylinder_ptr;

struct						s_sphere
{
	t_vec3_ptr				cords;
	double					diameter;
	t_vec3_ptr				color;
};

struct						s_plane
{
	t_vec3_ptr				cords;
	t_vec3_ptr				norm;
	t_vec3_ptr				color;
};

struct						s_cylinder
{
	t_vec3_ptr				cords;
	t_vec3_ptr				norm;
	double					diameter;
	double					height;
	t_vec3_ptr				color;
};

#endif
