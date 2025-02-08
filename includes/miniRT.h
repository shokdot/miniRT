/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:02:17 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/08 22:31:34 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <libft.h>
# include <list_c.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define AMBIENT_TOKEN 3
# define CAMERA_TOKEN 4
# define LIGHT_TOKEN 3
# define SPHERE_TOKEN 4
# define PLANE_TOKEN 4
# define CYLINDER_TOKEN 6
# define COLOR_TOKEN 3

# define UNUSED __attribute__((unused))

typedef struct s_tracer	t_tracer;
typedef t_tracer		*t_tracer_ptr;

struct					s_tracer
{
	int					fd;
};

void					args_check(int argc, char **argv);
t_tracer_ptr			init_data(void);
void					parsing(char *filename, t_tracer_ptr data);

// utils
void					free_matrix(char **matrix);
void					print_matrix(char **line);
void					empty_map_free(t_tracer_ptr tracer);
void					tab_to_space(char *line);
int						count_token(char **line);
void					free_line_map(char **line, t_tracer_ptr tracer);
bool					is_line_empty(char *line);
bool					is_matrix_empty(char **matrix);
bool					skip_check(char **line);

// parse objects
void					parse_ambient(char **line, t_tracer_ptr tracer);
void					parse_light(char **line, t_tracer_ptr tracer);
void					parse_camera(char **line, t_tracer_ptr tracer);
bool					parse_color(char *line);
bool					parse_fov(char *line);
bool					parse_ratio(char *line);

// parse figures
void					parse_sphere(char **line, t_tracer_ptr tracer UNUSED);
void					parse_plane(char **line, t_tracer_ptr tracer UNUSED);
void					parse_cylinder(char **line, t_tracer_ptr tracer UNUSED);

#endif
