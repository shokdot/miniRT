/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:00:43 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/01 13:43:00 by tigran           ###   ########.fr       */
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
	init_lib(tracer);
	render(tracer);
	mlx_handler(tracer);
}
