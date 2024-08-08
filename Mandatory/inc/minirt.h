/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:03:29 by user              #+#    #+#             */
/*   Updated: 2024/08/08 16:49:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdio.h>
# include "../../Libft/libft.h"
# include <math.h>
# include <stdint.h>

# ifdef __linux__
#  include "../../MLX/minilibx_linux/mlx.h"
# else
#  include "../../MLX/minilibx_ogl/mlx.h"
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifdef __linux__
#  define W_KEY 119
#  define S_KEY 115
#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define RIGHT_KEY 65363
#  define LEFT_KEY 65361
#  define ESC 65307

# else
#  define W_KEY	13
#  define S_KEY	1
#  define UP_KEY	126
#  define DOWN_KEY	125
#  define RIGHT_KEY	124
#  define LEFT_KEY	123
#  define ESC	53
# endif

// SETTINGS
# define WIDTH	500
# define HEIGHT	500
# define THRESHOLD	1

// DIFFUSE RAY SETTINGS
# define SAMPLES 1
# define DIFFUSE_RAY_LIMIT 1
# define DIFFUSE_RAY_BOUNCES 0

// RANDOM SEED GEN
# define SEED_A 1664525
# define SEED_C 1013904223
# define SEED_M 4294967296

typedef struct s_v3
{
	double	x;
	double	y;
	double	z;
}	t_v3;

typedef struct s_cam
{
	t_v3	pos;
	t_v3	normal;
	double	fov;
}	t_cam;

typedef struct s_matrix
{
	double	d[4][4];
}	t_matrix;

typedef struct s_ray
{
	t_v3	origin;
	t_v3	direction;
}	t_ray;

typedef struct s_sphere
{
	t_v3	pos;
	double	radius;
	int		color;
}	t_sphere;

typedef struct s_plane
{
	t_v3	pos;
	t_v3	normal;
	int		color;
}	t_plane;

typedef struct s_cylinder
{
	t_v3	pos;
	t_v3	normal;
	double	radius;
	double	height;
	int		color;
}	t_cylinder;

typedef enum e_objs
{
	SPHERE,
	PLANE,
	CYLINDER,
	A_LIGHT,
	P_LIGHT,
}	t_objs;

typedef struct s_light
{
	double	intensity;
	int		color;
	t_v3	pos;
	t_objs	type;
}	t_light;

typedef struct s_objects
{
	void				*data;
	t_objs				type;
	int					id;
	struct s_objects	*next;
}	t_objects;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_cam		*camera;
	t_objects	*objects;
	int			update;
	int			size[2];
}	t_vars;

// minirt.c
int				intersect(t_vars *vars, t_v3 pixel);

// check_arguments.c
int				check_arguments(int ac, char **av);

// normals.c
void			normalize(t_v3 *vector);

// vec3_maths.c
t_v3			subtract_vectors(const t_v3 a, const t_v3 b);
t_v3			add_vectors(const t_v3 a, const t_v3 b);
double			dot(const t_v3 a, const t_v3 b);
int				cam_normal(t_vars *vars, char a);
int				min(int a, int b);
double			min_double(double a, double b);

// vec3_maths_2.c
t_v3			cross(const t_v3 a, const t_v3 b);
t_v3			scale_vector(const t_v3 v, double scale);
double			*solve_quadratic_eq(double a, double b, double c,
					double *lim_dep);
double			vec_len(const t_v3 a, const t_v3 b);
t_v3			divide_vector(const t_v3 v, double div);

// vec3_maths_3.c
t_v3			create_v3(double x, double y, double z);

// plane.c
t_plane			*set_plane();
int				set_plane_color(t_plane *plane, double *t);
double			*hit_plane(t_plane *plane, const t_ray *ray, double *lim_dep);
t_ray			plane_hitray(t_plane *plane, double *t, t_ray *ray);
t_v3			plane_normal(t_plane *plane);

// camera.c
t_cam			*set_cam();
int				cam_normal(t_vars *vars, char a);

// MATRIX.C
t_matrix		look_at(t_v3 origin, t_v3 cam_vector);
t_v3			multiply_by_matrix(t_v3 p, t_matrix m);

// sphere.c
t_sphere		*set_sphere(double x, double y, double z, int color);
int				set_sphere_color(t_sphere *sphere, double *t);
double			*hit_sphere(t_sphere *sphere, const t_ray *ray,
					double *lim_dep);
int				diffuse(t_ray ray, t_objects *obj, t_objects *w_objs,
					double *lim_dep);
t_ray			sphere_hitray(t_sphere *sphere, double *t, t_ray *ray);
t_v3			sphere_normal_at_point(t_sphere *sphere, t_v3 point);

// colors.c
int				create_trgb(int t, int r, int g, int b);
int				math_colors(int color1, int color2, int asmd);
int				avg_color(int color1, int color2, int color3, int color4);
int				avg_color_2(int color1, int color2);
int				math_color_by(int color1, double num, int muldiv);

// colors_2.c
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

// objects.c
t_objects		*load_objects();
t_objects		*get_objects(t_objects *obj, int change);
t_v3			normal_at_intersection(t_objects *obj, t_v3 point);

// exit.c
void			free_objects(t_objects *obj);
void			free_program(t_vars *vars);
int				quit(t_vars *vars);

// controls.c
int				events(int keycode, t_vars *vars);

// anti_alias.c
void			anti_alias(t_vars *vars);
int				store_render(int update, int x, int y, int color);
void			modify_pixel(t_vars *vars, int x, int y);

// render.c
int				render(t_vars *vars);

// ray_trace.c
int				ray_trace(t_objects *obj, t_ray ray, int color,
					double *lim_dep);
double			*hit_object(t_objects *obj, t_ray *ray, double *lim_dep);

// rand_ray.c
t_ray			random_ray(t_v3 normal, t_v3 origin);

// data_manage.c
int				data_color(t_objects *obj, double *t);
double			*hit_object(t_objects *obj, t_ray *ray, double *lim_dep);
void			*return_type(t_objects	*world, t_objs type);

// lights.c
t_light			*set_light(t_v3 pos, double intensity, int color);
int				ambi_int(t_objects *world);
int				compute_light_shadow(t_objects *world,
					t_objects *object, int diffuse, t_ray *ray);

// cylinder.c
t_ray			cylinder_hitray(t_cylinder *cylinder, double *t, t_ray *ray);
int				set_cylinder_color(t_cylinder *cylinder, double *t);
t_cylinder		*set_cylinder(double x, double y, double z, int color);
int				is_in_bounds(t_v3 hit_point, t_cylinder *cylinder,
					const t_ray *ray);

// cylinder_2.c
double			*hit_cylinder(t_cylinder *cylinder, const t_ray *ray,
					double *lim_dep);
t_v3			hit_cord(const t_ray *ray, double *t);

#endif
