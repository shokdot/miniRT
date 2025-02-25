/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:42:58 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/25 17:07:55 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACER_H
# define TRACER_H

# include <figures.h>
# include <list_c.h>
# include <objects.h>

typedef struct s_tracer	t_tracer;
typedef t_tracer		*t_tracer_ptr;

typedef struct s_mlx	t_mlx;
typedef t_mlx			*t_mlx_ptr;

typedef struct s_scene	t_scene;
typedef t_scene			*t_scene_ptr;

typedef struct s_img	t_img;
typedef t_img			*t_img_ptr;

typedef struct s_vplane	t_vplane;
typedef t_vplane		*t_vplane_ptr;

struct					s_tracer
{
	int					fd;
	t_scene_ptr			scene;
	t_mlx_ptr			mlx;
	t_img_ptr			img;
};

struct					s_mlx
{
	void				*mlx;
	void				*mlx_win;
};

struct					s_scene
{
	t_ambient_ptr		ambient;
	t_camera_ptr		camera;
	t_light_ptr			light;
	t_list_ptr			figures;
	t_vplane_ptr		vplane;
	int					amb_count;
	int					cam_count;
	int					lgt_count;
};

struct					s_img
{
	void				*img;
	char				*img_data;
	int					bpp;
	int					size_line;
	int					endian;
};

struct					s_vplane
{
	double				width;
	double				height;
	double				pixel_dx;
	double				pixel_dy;
};

#endif
