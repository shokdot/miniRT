/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_mv_lt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:30:27 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/20 19:03:58 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

void	push_back_mv_lt(t_list_ptr list, void *data, t_obj_type obj_type)
{
	t_node_ptr	curr;

	if (!list)
		return ;
	if (!list->head)
	{
		list->tail = make_node_mv(data, obj_type);
		list->head = list->tail;
	}
	else
	{
		curr = make_node_mv(data, obj_type);
		curr->prev = list->tail;
		list->tail->next = curr;
		list->tail = curr;
	}
	++(list->size);
}
