/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:42:58 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/22 22:56:23 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

# include <figures.h>
# include <list_c.h>
# include <objects.h>

typedef struct s_tracer		t_tracer;
typedef t_tracer			*t_tracer_ptr;

typedef struct s_mlx		t_mlx;
typedef t_mlx				*t_mlx_ptr;

typedef struct s_ambient	t_ambient;
typedef t_ambient			*t_ambient_ptr;

typedef struct s_camera		t_camera;
typedef t_camera			*t_camera_ptr;

typedef struct s_light		t_light;
typedef t_light				*t_light_ptr;

struct						s_tracer
{
	int						fd;
	t_list_ptr				figures;
	t_mlx					*mlx;
};

struct						s_mlx
{
	void					*mlx;
	void					*mlx_win;
};

#endif
