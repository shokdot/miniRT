/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 02:48:16 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/22 16:07:29 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

void	clear_lt(t_list_ptr *list)
{
	t_node_ptr	curr;

	if (!list)
		return ;
	curr = (*list)->head;
	while (curr)
	{
		(*list)->head = (*list)->head->next;
		free_node_lt(&curr);
		curr = (*list)->head;
	}
	ft_free((void **)list);
}
