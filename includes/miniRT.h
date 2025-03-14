/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:02:17 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/11 16:33:40 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <libft.h>
# include <list_c.h>
# include <math.h>
# include <mlx.h>
# include <ray.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <tracer.h>
# include <unistd.h>

void			args_check(int argc, char **argv);
void			parsing(char *filename, t_tracer_ptr data);

// utils
int				vec3_to_hex(t_vec3 color, double intensity);
void			print_matrix(char **line);
void			tab_to_space(char *line);
int				count_token(char **line);
bool			is_line_empty(char *line);
bool			is_matrix_empty(char **matrix);
bool			skip_check(char **line);
bool			float_parse(char *line);
double			deg_to_rad(double degrees);
double			intersect_sphere(t_ray ray, t_sphere_ptr sphere);
double			intersect_plane(t_ray ray, t_plane_ptr plane);
double			intersect_cylinder(t_ray ray, t_cylinder_ptr cylinder);
double			check_intersection(t_node_ptr figure, t_ray ray);
void			mlx_handler(t_tracer_ptr tracer);
double			calculate_discriminant(double a, double b, double c_term);

// figure API
t_vec3			get_figure_color(t_node_ptr figure);
t_vec3			get_figure_cords(t_node_ptr figure);
t_vec3			get_figure_normal(t_node_ptr node, t_vec3 hit_point);

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
void			check_obj_count(t_tracer_ptr tracer);

// init
void			init_lib(t_tracer_ptr tracer);
void			init_mlx(t_tracer_ptr tracer);
void			init_img(t_tracer_ptr tracer);
void			init_vplane(t_tracer_ptr tracer);
t_vec3_ptr		init_vec3(char *line);
t_tracer_ptr	init_data(void);
t_scene_ptr		init_scene(void);
void			init_vcam(t_tracer_ptr tracer);
t_ray_ptr		init_ray(t_vec3 origin, t_vec3 direction);

// fill_data
void			fill_ambient_struct(char **line, t_tracer_ptr tracer);
void			fill_camera_struct(char **line, t_tracer_ptr tracer);
void			fill_cylinder_struct(char **line, t_tracer_ptr tracer);
void			fill_light_struct(char **line, t_tracer_ptr tracer);
void			fill_plane_struct(char **line, t_tracer_ptr tracer);
void			fill_sphere_struct(char **line, t_tracer_ptr tracermkae);

// free
void			free_open_err(t_tracer_ptr tracer);
void			free_matrix(char **matrix);
void			free_empty_map(t_tracer_ptr tracer);
void			free_line_map(char **line, t_tracer_ptr tracer);
void			free_obj_tracer(t_tracer_ptr tracer);
void			free_mlx(t_mlx_ptr mlx);
void			free_scene(t_scene_ptr scene);
void			free_destroy(t_tracer_ptr tracer);
void			free_lib(t_tracer_ptr tracer);
void			free_ray(t_ray_ptr ray);

// free_figures
void			free_figures(t_list_ptr figures);
void			free_sphere(t_sphere_ptr obj);
void			free_plane(t_plane_ptr obj);
void			free_cylinder(t_cylinder_ptr obj);

// free_objects
void			free_objs(t_scene_ptr scene);
void			free_ambient(t_ambient_ptr obj);
void			free_camera(t_camera_ptr obj);
void			free_light(t_light_ptr obj);

// render
void			render(t_tracer_ptr tracer);
double			calculate_lighting(t_vec3 hit_point, t_vec3 normal,
					t_scene_ptr scene, t_node_ptr self);
void			tracing(t_tracer_ptr tracer);

// tracer utils
void			put_pixel(t_tracer_ptr tracer, int x, int y, int color);
t_vec3			get_cylinder_normal(t_cylinder_ptr obj, t_vec3 hit_point);
t_vec3			calc_cap_center(t_cylinder_ptr cylinder, int top);
t_vec3			cyl_compute_cofficent(t_ray ray, t_cylinder_ptr cyl);
double			compute_side_candidate(t_ray ray, t_cylinder_ptr cyl, double t1,
					double t2);
t_ray_ptr		ray_calculate(int x, int y, t_tracer_ptr tracer);

#endif
