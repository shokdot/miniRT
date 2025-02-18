/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:42:58 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/18 16:58:17 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_tracer		t_tracer;
typedef t_tracer			*t_tracer_ptr;

typedef struct s_vec3		t_vec3;
typedef t_vec3				*t_vec3_ptr;

typedef struct s_ambient	t_ambient;
typedef t_ambient			*t_ambient_ptr;

typedef struct s_camera		t_camera;
typedef t_camera			*t_camera_ptr;

typedef struct s_light		t_light;
typedef t_light				*t_light_ptr;

typedef struct s_sphere		t_sphere;
typedef t_sphere			*t_sphere_ptr;

typedef struct s_plane		t_plane;
typedef t_plane				*t_plane_ptr;

typedef struct s_cylinder	t_cylinder;
typedef t_cylinder			*t_cylinder_ptr;

struct						s_tracer
{
	int						fd;
	t_list_ptr				figures;
};

struct						s_vec3
{
	double					x;
	double					y;
	double					z;
};

struct						s_ambient
{
	char					*type;
	double					ratio;
	t_vec3_ptr				color;
};

struct						s_camera
{
	char					*type;
	t_vec3_ptr				cords;
	t_vec3_ptr				norm;
	int						fov;
};

struct						s_light
{
	char					*type;
	t_vec3_ptr				cords;
	double					ratio;
	t_vec3_ptr				color;
};

struct						s_sphere
{
	char					*type;
	t_vec3_ptr				cords;
	double					diameter;
	t_vec3_ptr				color;
};

struct						s_plane
{
	char					*type;
	t_vec3_ptr				cords;
	t_vec3_ptr				norm;
	t_vec3_ptr				color;
};

struct						s_cylinder
{
	char					*type;
	t_vec3_ptr				cords;
	t_vec3_ptr				norm;
	double					diameter;
	double					height;
	t_vec3_ptr				color;
};

#endif
