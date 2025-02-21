/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:02:17 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/21 15:46:35 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <libft.h>
# include <list_c.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <structs.h>
# include <unistd.h>

# define AMBIENT_TOKEN 3
# define CAMERA_TOKEN 4
# define LIGHT_TOKEN 3
# define SPHERE_TOKEN 4
# define PLANE_TOKEN 4
# define CYLINDER_TOKEN 6
# define COLOR_TOKEN 3
# define CORDS_TOKEN 3

# define UNUSED __attribute__((unused))

void			args_check(int argc, char **argv);
void			parsing(char *filename, t_tracer_ptr data);

// utils
void			free_matrix(char **matrix);
void			print_matrix(char **line);
void			empty_map_free(t_tracer_ptr tracer);
void			tab_to_space(char *line);
int				count_token(char **line);
void			free_line_map(char **line, t_tracer_ptr tracer);
bool			is_line_empty(char *line);
bool			is_matrix_empty(char **matrix);
bool			skip_check(char **line);
bool			float_parse(char *line);
void			free_obj_tracer(t_tracer_ptr tracer);

// parse objects
void			parse_ambient(char **line, t_tracer_ptr tracer);
void			parse_light(char **line, t_tracer_ptr tracer);
void			parse_camera(char **line, t_tracer_ptr tracer);
bool			parse_color(char *line);
bool			parse_fov(char *line);
bool			parse_ratio(char *line);
bool			parse_cords(char *line);
bool			parse_norm_vec(char *line);

// parse figures
void			parse_sphere(char **line, t_tracer_ptr tracer);
void			parse_plane(char **line, t_tracer_ptr tracer);
void			parse_cylinder(char **line, t_tracer_ptr tracer);

// validation
void			validation_ambient(char **line, t_tracer_ptr tracer);
void			validation_light(char **line, t_tracer_ptr tracer);
void			validation_camera(char **line, t_tracer_ptr tracer);
void			validation_sphere(char **line, t_tracer_ptr tracer);
void			validation_plane(char **line, t_tracer_ptr tracer);
void			validation_cylinder(char **line, t_tracer_ptr tracer);
void			check_dublicates(t_tracer_ptr tracer);

// init
t_mlx_ptr		init_mlx(void);
t_vec3_ptr		init_vec3(char *line);
t_tracer_ptr	init_data(void);

// fill_data
void			fill_ambient_struct(char **line, t_tracer_ptr tracer);
void			fill_camera_struct(char **line, t_tracer_ptr tracer);
void			fill_cylinder_struct(char **line, t_tracer_ptr tracer);
void			fill_light_struct(char **line, t_tracer_ptr tracer);
void			fill_plane_struct(char **line, t_tracer_ptr tracer);
void			fill_sphere_struct(char **line, t_tracer_ptr tracermkae);

// free_objects
void			free_objs(t_list_ptr objs);
void			free_ambient(t_ambient_ptr obj);
void			free_camera(t_camera_ptr obj);
void			free_cylinder(t_cylinder_ptr obj);
void			free_light(t_light_ptr obj);
void			free_plane(t_plane_ptr obj);
void			free_sphere(t_sphere_ptr obj);

#endif
