/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:00:43 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/28 14:54:19 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	destory(t_tracer_ptr tracer UNUSED)
{
	mlx_clear_window(tracer->mlx->mlx, tracer->mlx->mlx_win);
	mlx_destroy_image(tracer->mlx->mlx, tracer->img->img);
	mlx_destroy_window(tracer->mlx->mlx, tracer->mlx->mlx_win);
	exit(0);
	return (0);
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
	mlx_hook(tracer->mlx->mlx_win, ON_DESTROY, NO_EVENT, destory, tracer);
	mlx_loop(tracer->mlx->mlx);
	printf("MAP is OK\n");
}
