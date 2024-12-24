/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:02:17 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/24 19:37:38 by healeksa         ###   ########.fr       */
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

typedef struct s_data	t_data;
typedef t_data			*t_data_ptr;

struct					s_data
{
	int					fd;
};

void					args_check(int argc, char **argv);
t_data_ptr				init_data(void);
void					parsing(char *filename, t_data_ptr data);

#endif
