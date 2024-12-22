/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_mv_lt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:30:27 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/22 01:26:34 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

void	push_back_mv_lt(t_list_ptr list, void *data)
{
	t_node_ptr	curr;

	if (!list)
		return ;
	if (!list->head)
	{
		list->tail = make_node_mv(data);
		list->head = list->tail;
	}
	else
	{
		curr = make_node_mv(data);
		list->head->prev = curr;
		curr->next = list->head;
		list->head = curr;
	}
	++(list->size);
}
