/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:00:43 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/11 19:41:29 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	gegh(void)
{
	system("leaks miniRT");
}

int	main(int argc, char **argv)
{
	t_tracer_ptr	tracer;

	atexit(gegh);
	args_check(argc, argv);
	tracer = init_data();
	parsing(argv[1], tracer);
	init_lib(tracer);
	render(tracer);
	mlx_handler(tracer);
}
