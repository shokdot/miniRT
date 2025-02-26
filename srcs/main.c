/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:00:43 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/26 22:32:28 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int argc, char **argv)
{
	t_tracer_ptr	tracer;

	args_check(argc, argv);
	tracer = init_data();
	parsing(argv[1], tracer);
	init_mlx(tracer);
	// render(tracer);
	mlx_loop_hook(tracer->mlx->mlx, render, tracer);
	mlx_loop(tracer->mlx->mlx);
	printf("MAP is OK\n");
}
