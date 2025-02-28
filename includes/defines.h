/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:59:00 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/28 14:48:02 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIDTH 1280
# define HEIGHT 700
# define RATIO 1.77

# define AMBIENT_TOKEN 3
# define CAMERA_TOKEN 4
# define LIGHT_TOKEN 3
# define SPHERE_TOKEN 4
# define PLANE_TOKEN 4
# define CYLINDER_TOKEN 6
# define COLOR_TOKEN 3
# define CORDS_TOKEN 3

# define ON_DESTROY 17
# define NO_EVENT 0

typedef enum e_obj_type	t_obj_type;

enum					e_obj_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
};

#endif
