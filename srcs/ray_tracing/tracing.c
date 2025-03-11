/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:15:08 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/11 19:56:23 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_node_ptr	get_nearest_obj(t_tracer_ptr tracer, t_ray_ptr ray,
		double *nearest_t)
{
	t_node_ptr	node;
	t_node_ptr	nearest_obj;
	double		t;

	*nearest_t = INFINITY;
	nearest_obj = NULL;
	node = tracer->scene->figures->head;
	while (node)
	{
		t = check_intersection(node, *ray);
		if (t > EPSILION && t < *nearest_t)
		{
			*nearest_t = t;
			nearest_obj = node;
		}
		node = node->next;
	}
	return (nearest_obj);
}

void	render_pixel(int x, int y, t_ray_ptr ray, t_tracer_ptr tracer)
{
	t_vec3		hit_point;
	t_vec3		normal;
	double		intensity;
	double		nearest_t;
	t_node_ptr	nearest_obj;

	nearest_obj = get_nearest_obj(tracer, ray, &nearest_t);
	if (nearest_obj)
	{
		hit_point = vec3_add(*(ray->origin), vec3_scale(*(ray->direction),
					nearest_t));
		normal = get_figure_normal(nearest_obj, hit_point);
		intensity = calculate_lighting(hit_point, normal, tracer->scene,
				nearest_obj);
		put_pixel(tracer, x, y, vec3_to_hex(get_figure_color(nearest_obj),
				intensity));
	}
	else
		put_pixel(tracer, x, y, 0xFFFFFF);
}

void	tracing(t_tracer_ptr tracer)
{
	int			y;
	int			x;
	t_ray_ptr	ray;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ray_calculate(WIDTH - x - 1, y, tracer);
			render_pixel(x, y, ray, tracer);
			free_ray(ray);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(tracer->mlx->mlx, tracer->mlx->mlx_win,
		tracer->img->img, 0, 0);
}
