/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:28 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/24 16:27:30 by ebichan          ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
// #define KEY_ESC 65307//Linux
#define KEY_ESC 53
#define EVENT_DESTROY_NOTIFY 17

typedef enum
{
    DOUBLE_ALL,
    DOUBLE_POSITIVE
}   double_range_mode;

typedef struct s_point
{
    double x;
    double y;
    double z;
}   t_point;

typedef struct s_vector
{
    double vx;
    double vy;
    double vz;
}   t_vector;

typedef struct s_color
{
    double r;
    double g;
    double b;
}   t_color;

typedef struct s_cylen
{
    double r;
    double h;
}   t_cylen;

typedef struct s_amb
{
    double   ratio;
    t_color color;
}   t_amb;

typedef struct s_camera
{
    t_point point;
    t_vector vector;
    double   fov;
}   t_camera;

typedef struct s_light
{
    t_point point;
    double   ratio;
    t_color color;
}   t_light;

typedef struct s_sphere
{
    t_point point;
    double   r;
    t_color color;
    t_sphere *next;
}   t_sphere;

typedef struct s_plane
{
    t_point point;
    t_vector vector;
    t_color color;
    t_plane *next;
}   t_plane;

typedef struct s_cylinder
{
    t_point point;
    t_vector vector;
    double r;
    double h;
    t_color color;
    t_cylinder *next;
}   t_cylinder;

typedef struct s_elem
{
    t_amb *amb;
    t_camera *camera;
    t_cylinder *cylinder;
    t_light *light;
    t_plane *plane;
    t_sphere *sphere;
    bool amb_flag;
    bool camera_flag;
    bool light_flag;
}   t_elem;

typedef struct s_minirt
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *addr;
    int bits_per_pixel;
    int size_line;
    int endian;
    t_elem *elem;
}   t_minirt;

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
ssize_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

#endif
