/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_node_lt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:28:50 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/22 17:00:59 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

t_node_ptr	get_index_node_lt(t_list_ptr list, int index)
{
	int			i;
	t_node_ptr	curr;

	i = 0;
	if (!list || index >= get_size_lt(list))
		return (NULL);
	else
	{
		curr = list->head;
		while (curr)
		{
			if (i == index)
				return (curr);
			curr = curr->next;
			i++;
		}
	}
	return (NULL);
}
