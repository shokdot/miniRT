/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_lt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:16:55 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/20 19:03:11 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

void	push_back_lt(t_list_ptr list, void *data, size_t size,
		t_obj_type obj_type)
{
	t_node_ptr	curr;

	if (!list || size <= 0)
		return ;
	if (!list->head)
	{
		list->tail = make_node(data, size, obj_type);
		list->head = list->tail;
	}
	else
	{
		curr = make_node(data, size, obj_type);
		curr->prev = list->tail;
		list->tail->next = curr;
		list->tail = curr;
	}
	++(list->size);
}
