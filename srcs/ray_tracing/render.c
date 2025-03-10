/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:07:13 by healeksa          #+#    #+#             */
/*   Updated: 2025/03/10 16:59:01 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	render(t_tracer_ptr tracer)
{
	t_ray_ptr	ray;
	double		t;
	double		nearest_t;
	t_node_ptr	node;
	t_node_ptr	nearest_obj;
	t_vec3		hit_point;
	t_vec3		normal;
	double		intensity;
	int			color;
	int			y;
	int			x;

	init_vplane(tracer);
	init_vcam(tracer);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = ray_calculate(x, y, tracer);
			nearest_t = INFINITY;
			nearest_obj = NULL;
			node = tracer->scene->figures->head;
			while (node)
			{
				t = check_intersection(node, *ray);
				if (t > EPSILION && t < nearest_t)
				{
					nearest_t = t;
					nearest_obj = node;
				}
				node = node->next;
			}
			if (nearest_obj)
			{
				hit_point = vec3_add(*(ray->origin),
						vec3_scale(*(ray->direction), nearest_t));
				normal = get_figure_normal(nearest_obj, hit_point);
				intensity = calculate_lighting(hit_point, normal, tracer->scene,
						nearest_obj);
				color = vec3_to_hex(get_figure_color(nearest_obj), intensity);
				put_pixel(tracer, x, y, color);
			}
			else
				put_pixel(tracer, x, y, 0xFFFFFF);
			free(ray);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(tracer->mlx->mlx, tracer->mlx->mlx_win,
		tracer->img->img, 0, 0);
}
