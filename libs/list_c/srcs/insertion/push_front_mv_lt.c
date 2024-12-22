/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front_mv_lt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:26:59 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/22 01:31:41 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

void	push_front_mv_lst(t_list_ptr list, void *data)
{
	t_node_ptr	curr;

	if (!list)
		return ;
	if (!list->head)
	{
		list->head = make_node_mv(data);
		list->tail = list->head;
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
