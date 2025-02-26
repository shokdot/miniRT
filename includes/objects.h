/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:47:15 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/26 19:29:57 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <vec3.h>

typedef struct s_ambient	t_ambient;
typedef t_ambient			*t_ambient_ptr;

typedef struct s_camera		t_camera;
typedef t_camera			*t_camera_ptr;

typedef struct s_light		t_light;
typedef t_light				*t_light_ptr;


struct						s_ambient
{
	double					ratio;
	t_vec3_ptr				color;
};

struct						s_camera
{
	t_vec3_ptr				cords;
	t_vec3_ptr				norm;
	int						fov;
};

struct						s_light
{
	t_vec3_ptr				cords;
	double					ratio;
};

#endif
