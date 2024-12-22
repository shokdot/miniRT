/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_lt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:16:55 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/21 22:21:55 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

void	push_back_lt(t_list_ptr list, void *data, size_t size)
{
	t_node_ptr	curr;

	if (!list || size <= 0)
		return ;
	if (!list->head)
	{
		list->head = make_node(data, size);
		list->tail = list->head;
	}
	else
	{
		curr = make_node(data, size);
		list->tail->next = curr;
		curr->prev = list->tail;
		list->tail = curr;
	}
	++(list->size);
}
