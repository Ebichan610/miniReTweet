/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:28 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/13 19:05:22 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef enum
{
	DOUBLE_ALL,
	DOUBLE_POSITIVE
}						double_range_mode;

typedef struct s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct s_vector
{
	double				vx;
	double				vy;
	double				vz;
}						t_vector;

typedef struct s_color
{
	double				r;
	double				g;
	double				b;
}						t_color;

typedef struct s_cylen
{
	double				r;
	double				h;
}						t_cylen;

typedef struct s_ray
{
	t_point				origin;
	t_vector			dir;
}						t_ray;

typedef struct s_hit
{
	double				t;
	t_point				point;
	t_vector			normal;
	t_color				color;
	bool				hit;
}						t_hit;

typedef struct s_amb
{
	double				ratio;
	t_color				color;
}						t_amb;

typedef struct s_camera
{
	t_point				point;
	t_vector			vector;
	double				fov;
}						t_camera;

typedef struct s_light
{
	t_point				point;
	double				ratio;
	t_color				color;
}						t_light;

typedef struct s_sphere
{
	t_point				point;
	double				r;
	t_color				color;
	struct s_sphere		*next;
}						t_sphere;

typedef struct s_plane
{
	t_point				point;
	t_vector			vector;
	t_color				color;
	struct s_plane		*next;
}						t_plane;

typedef struct s_cylinder
{
	t_point				point;
	t_vector			vector;
	double				r;
	double				h;
	t_color				color;
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct s_elem
{
	t_amb				*amb;
	t_camera			*camera;
	t_cylinder			*cylinder;
	t_light				*light;
	t_plane				*plane;
	t_sphere			*sphere;
	bool				amb_flag;
	bool				camera_flag;
	bool				light_flag;
}						t_elem;

typedef struct s_minirt
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_elem				*elem;
}						t_minirt;

void					print_error(char *s);
void					free_elem(t_elem *elem);
void					free_strs(char **strs);
int						free_all(t_minirt *minirt);
double					ft_atof(const char *nptr);
char					**ft_split_space(char *str);
size_t					count_str(char **strs);
int						ft_strcmp(const char *s1, const char *s2);
bool					ft_isspace(char c);
bool					check_positive_int_num(char *str);
bool					is_zero_vector(t_vector vector);
t_point					apply_point(char *str);
t_vector				apply_vector(char *str);
t_color					apply_color(char *str);
char					*get_next_line(int fd);
bool					in_ratio_range(char *nptr);
bool					in_color_range(char *nptr);
bool					in_double_range(char *nptr, double_range_mode mode);
bool					in_vector_range(char *nptr);
bool					in_degree_range(char *nptr);
bool					parse_amb(t_elem *elem, char **strs);
bool					parse_camera(t_elem *elem, char **strs);
bool					parse_light(t_elem *elem, char **strs);
bool					parse_sphere(t_elem *elem, char **strs);
bool					parse_plane(t_elem *elem, char **strs);
bool					parse_cylinder(t_elem *elem, char **strs);
t_elem					*read_file(char *filename);
t_hit					hit_cylinder(t_ray ray, t_cylinder *cylinder);
t_vector				get_plane_normal(t_ray ray, t_plane *plane);
t_hit					hit_plane(t_ray ray, t_plane *plane);
double					solve_quadratic(double a, double b, double disc);
t_point					ray_at(t_ray ray, double t);
t_vector				get_sphere_normal(t_point hit_point, t_sphere *sphere);
t_hit					hit_sphere(t_ray ray, t_sphere *sphere);
t_color					color_add(t_color a, t_color b);
t_color					color_mul(t_color c, double t);
t_color					color_mul_color(t_color a, t_color b);
int						color_to_int(t_color c);
void					my_pixel_put(t_minirt *minirt, int x, int y, int color);
void					drawing_picture(t_minirt *minirt);
t_color					calc_lighting(t_minirt *minirt, t_hit hit);
void					get_camera_axes(t_camera *camera, t_vector *right,
							t_vector *up);
double					x_pixel_normalize(t_camera *camera, int x);
double					y_pixel_normalize(t_camera *camera, int y);
t_vector				get_ray_dir(t_camera *camera, t_vector u_right,
							t_vector v_up);
t_ray					create_ray(t_minirt *minirt, int x, int y);
bool					is_in_shadow(t_minirt *minirt, t_hit hit);
t_vector				vec_add(t_vector a, t_vector b);
t_vector				vec_sub(t_vector a, t_vector b);
t_vector				vec_mul(t_vector v, double t);
double					vec_dot(t_vector a, t_vector b);
t_vector				vec_cross(t_vector a, t_vector b);
t_vector				vec_normalize(t_vector a);
t_vector				vec_sub_point(t_point a, t_point b);
t_minirt				*init_minirt(char *filename);
void					setup_hooks(t_minirt *minirt);

#endif
