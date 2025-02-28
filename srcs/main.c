/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:00:43 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/28 17:27:20 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void exit_win(t_tracer_ptr tracer UNUSED)
{
	printf("Window closed\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_tracer_ptr	tracer;

	args_check(argc, argv);
	tracer = init_data();
	parsing(argv[1], tracer);
	init_mlx(tracer);
	render(tracer);
	// mlx_loop_hook(tracer->mlx->mlx, tracer);
	mlx_hook(tracer->mlx->mlx_win, CLOSE_WIN, 0, (void*)exit_win, tracer);
	mlx_loop(tracer->mlx->mlx);
	printf("MAP is OK\n");
}
