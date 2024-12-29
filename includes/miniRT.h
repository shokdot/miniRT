/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:02:17 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/29 16:33:07 by healeksa         ###   ########.fr       */
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

bool					is_line_empty(char *line);
bool					is_matrix_empty(char **matrix);
#endif
