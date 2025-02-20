/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:01:03 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/20 18:45:18 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_c.h>

t_node_ptr	make_node_mv(void *data, t_obj_type obj_type)
{
	t_node_ptr	node;

	node = (t_node_ptr)ft_malloc(sizeof(t_node));
	node->obj_type = obj_type;
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
