/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front_mv_lt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:26:59 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/20 18:51:02 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

void	push_front_mv_lst(t_list_ptr list, void *data, t_obj_type obj_type)
{
	t_node_ptr	curr;

	if (!list)
		return ;
	if (!list->head)
	{
		list->head = make_node_mv(data, obj_type);
		list->tail = list->head;
	}
	else
	{
		curr = make_node_mv(data, obj_type);
		list->head->prev = curr;
		curr->next = list->head;
		list->head = curr;
	}
	++(list->size);
}
