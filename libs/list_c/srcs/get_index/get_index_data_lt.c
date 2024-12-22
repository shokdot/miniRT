/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_data_lt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:02:39 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/22 17:03:16 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

void	*get_index_data_lt(t_list_ptr list, int index)
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
				return (curr->data);
			curr = curr->next;
			i++;
		}
	}
	return (NULL);
}
