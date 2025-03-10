/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:00:43 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 17:52:26 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	foo(void)
{
	system("leaks -q miniRT");
}

int	main(int argc, char **argv)
{
	t_tracer_ptr	tracer;

	atexit(foo);
	args_check(argc, argv);
	tracer = init_data();
	parsing(argv[1], tracer);
	init_lib(tracer);
	// render(tracer);
	mlx_handler(tracer);
}
