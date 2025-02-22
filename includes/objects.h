/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:47:15 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/22 22:53:43 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <vec3.h>

struct			s_ambient
{
	double		ratio;
	t_vec3_ptr	color;
};

struct			s_camera
{
	t_vec3_ptr	cords;
	t_vec3_ptr	norm;
	int			fov;
};

struct			s_light
{
	t_vec3_ptr	cords;
	double		ratio;
};

#endif
