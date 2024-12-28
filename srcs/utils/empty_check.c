/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:57:02 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/28 22:24:46 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

bool	is_line_empty(char *line)
{
	return (!line || !line[0]);
}

bool	is_matrix_empty(char **matrix)
{
	return (!matrix || !matrix[0] || !matrix[0][0]);
}
