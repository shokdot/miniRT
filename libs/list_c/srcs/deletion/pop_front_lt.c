/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_front_lt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:40:55 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/22 02:14:51 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

void	pop_front_lt(t_list_ptr list)
{
	t_node_ptr	curr;

	if (!is_empty_lt(list))
	{
		if (get_size_lt(list) == 1)
		{
			free_node_lt(&list->head);
			list->head = NULL;
			list->tail = NULL;
		}
		else
		{
			curr = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;
			free_node_lt(&curr);
		}
		--(list->size);
	}
	else
		perror("List empty");
}
