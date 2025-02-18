/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:42:58 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/18 15:38:31 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_tracer	t_tracer;
typedef t_tracer		*t_tracer_ptr;

typedef struct s_vec3	t_vec3;

struct					s_tracer
{
	int					fd;
};

struct					s_vec3
{
	double				x;
	double				y;
	double				z;
};

struct					s_ambient
{
	char				*type;
	double				ratio;
	t_vec3				*color;
};

struct					s_camera
{
	char				*type;
	t_vec3				*cords;
	t_vec3				*norm;
	int					fov;
};

struct					s_light
{
	char				*type;
	t_vec3				*cords;
	double				ratio;
	t_vec3				*color;
};

struct					s_sphere
{
	char				*type;
	t_vec3				*cords;
	double				diameter;
	t_vec3				*color;
};

struct					s_plane
{
	char				*type;
	t_vec3				*cords;
	t_vec3				*norm;
	t_vec3				*color;
};

struct					s_cylinder
{
	char				*type;
	t_vec3				*cords;
	t_vec3				*norm;
	double				diameter;
	double				height;
	t_vec3				*color;
};

#endif
