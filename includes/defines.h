/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:59:00 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/22 23:00:35 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define AMBIENT_TOKEN 3
# define CAMERA_TOKEN 4
# define LIGHT_TOKEN 3
# define SPHERE_TOKEN 4
# define PLANE_TOKEN 4
# define CYLINDER_TOKEN 6
# define COLOR_TOKEN 3
# define CORDS_TOKEN 3

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
