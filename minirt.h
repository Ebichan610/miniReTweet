/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:28 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/09 17:25:11 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include "mlx.h"
#include "libft.h"
#include <fcntl.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/time.h>

typedef enum
{
    DOUBLE_ALL,
    DOUBLE_POSITIVE
}   double_range_mode;

typedef struct s_amb
{
    double   ratio;
    double   red;
    double   green;
    double   blue;
}   t_amb;

typedef struct s_camera
{
    double   x;
    double   y;
    double   z;
    double   vx;
    double   vy;
    double   vz;
    double   fov;
}   t_camera;

typedef struct s_light
{
    double   x;
    double   y;
    double   z;
    double   ratio;
    double   red;
    double   green;
    double   blue;
}   t_light;

typedef struct s_sphere
{
    double   x;
    double   y;
    double   z;
    double   r;
    double   red;
    double   green;
    double   blue;
}   t_sphere;

typedef struct s_plane
{
    double   x;
    double   y;
    double   z;
    double   vx;
    double   vy;
    double   vz;
    double   red;
    double   green;
    double   blue;
}   t_plane;

typedef struct s_cylinder
{
    double   x;
    double   y;
    double   z;
    double   vx;
    double   vy;
    double   vz;
    double   r;
    double   h;
    double   red;
    double   green;
    double   blue;
}   t_cylinder;

typedef struct s_minirt
{

}   t_minirt;

typedef struct s_elem
{

}   t_elem;

#endif