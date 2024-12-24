/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:38:14 by healeksa          #+#    #+#             */
/*   Updated: 2024/12/24 19:30:41 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_data_ptr	init_data(void)
{
	t_data_ptr	data;

	data = (t_data_ptr)ft_malloc(sizeof(t_data));
	data->fd = 0;
	return (data);
}
