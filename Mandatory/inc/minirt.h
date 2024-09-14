/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:03:29 by user              #+#    #+#             */
/*   Updated: 2024/09/14 14:13:43 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdio.h>
# include "../../Libft/libft.h"
# include "../src/gnl/get_next_line.h"
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
#  define E	14
#  define R	15
#  define F1	122
#  define F2	120
# endif

// SETTINGS
# define WIDTH	800
# define HEIGHT	450
# define WIDTH_LD 400
# define HEIGHT_LD 225
# define THRESHOLD	1

// DIFFUSE RAY SETTINGS
# define SAMPLES 1
# define DIFFUSE_RAY_LIMIT 1
# define DIFFUSE_RAY_BOUNCES 0

// RANDOM SEED GEN
# define SEED_A 1664525
# define SEED_C 1013904223
# define SEED_M 4294967296

typedef struct s_properties
{
	double				value;
	char				*name;
	struct s_properties	*next;
}	t_properties;

typedef struct s_layer
{
	void	*object;
	char	*name;
	int		active;
}	t_layer;

typedef struct s_active_layers
{
	t_layer	*a;
	t_layer	*b;
	t_layer	*c;
	t_layer	*d;
	t_layer	*e;
}	t_active_layers;

typedef struct s_layers
{
	void				*sel_box;
	void				*main_box;
	t_active_layers		*active_layers;
}	t_layers;


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
	t_v3	up;
	t_v3	right;
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
	int			mode;
}	t_vars;

// minirt.c
int				intersect(t_vars *vars, t_v3 pixel);

// check_arguments.c
t_objects		*check_arguments(int ac, char **av);

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
t_cam			*get_camera(t_cam *cam, int set);

// MATRIX.C
t_matrix		look_at(t_v3 origin, t_v3 cam_vector, t_cam *cam);
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
t_objects		*_objects(t_objects *obj, int change);
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
int				low_res_render(t_objects *obj, t_ray ray,
					int color, double *lim_dep);

// ray_trace.c
int				ray_trace(t_objects *obj, t_ray ray, int color,
					double *lim_dep);
double			*hit_object(t_objects *obj, t_ray *ray, double *lim_dep);
int				bounce_ray(t_ray ray, t_objects *hit, t_objects *main,
					double *lim_dep);

// rand_ray.c
t_ray			random_ray(t_v3 normal, t_v3 origin);

// data_manage.c
int				data_color(t_objects *obj, double *t);
double			*hit_object(t_objects *obj, t_ray *ray, double *lim_dep);
void			*return_type(t_objects	*world, t_objs type);

// lights.c
t_light			*set_light(t_v3 pos, double intensity, int color);
int				ambi_int(t_objects *world, int color);
int				compute_light_shadow(t_objects *world,
					t_objects *object, int diffuse, t_ray *ray);

// cylinder.c
t_ray			cylinder_hitray(t_cylinder *cylinder, double *t, t_ray *ray);
int				set_cylinder_color(t_cylinder *cylinder, double *t);
t_cylinder		*set_cylinder(double x, double y, double z, int color);
int				is_in_bounds(t_v3 hit_point, t_cylinder *cylinder,
					const t_ray *ray);
t_v3			cylinder_surface_normal(t_cylinder *cy, t_v3 hit_pt);

// cylinder_2.c
double			*hit_cylinder(t_cylinder *cylinder, const t_ray *ray,
					double *lim_dep);
t_v3			hit_cord(const t_ray *ray, double *t);

//parse.c

int 	read_file(char *readfile, t_objects *objects);
int 	read_test(char *test, t_objects *objects);

//Checking the type
int		check_ambient(char *str, t_objects *objects);
int		check_camera(char *str, t_objects *objects);
int		check_light(char *str, t_objects *objects);
int		check_sphere(char *str, t_objects *objects);
int		check_plane(char *str, t_objects *objects);
int		check_cylinder(char *str, t_objects *objects);

//Check for Range
int		check_rgb_range(float rgb[3]);
int		check_lighting_range(float lighting);
int		check_normal_range(float rgb[3]);
int		check_fov_range(float fov); 

//Only for printing the values (Can be removed)
void 	print_split_result(char **split_result);
void 	print_array_char(char **arr);
void 	print_array_float(float *rgb); 

//parse items
int		parse_xyz(char *input, float xyz[3]);
int		parse_normal(char *input, float normal[3]);
int		parse_rgb(char *input, float rgb[3]);

#endif
