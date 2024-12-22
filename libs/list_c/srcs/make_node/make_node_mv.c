/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:01:03 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/21 20:28:24 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

t_node_ptr	make_node_mv(void *data)
{
	t_node_ptr	node;

	node = (t_node_ptr)ft_malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
