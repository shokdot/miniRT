/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:00:43 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/21 15:48:32 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	foo(void)
{
	system("leaks miniRT");
}

int	main(int argc, char **argv)
{
	t_tracer_ptr	tracer;

	// atexit(foo);
	args_check(argc, argv);
	tracer = init_data();
	parsing(argv[1], tracer);
	printf("MAP is OK\n");
	free_obj_tracer(tracer);
}
