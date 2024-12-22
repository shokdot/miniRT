/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:46:48 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/19 13:56:06 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

t_list_ptr	init_lt(void)
{
	t_list_ptr	list;

	list = (t_list_ptr)ft_malloc(sizeof(t_list));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}
