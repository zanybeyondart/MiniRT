/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:03:29 by user              #+#    #+#             */
/*   Updated: 2024/07/19 17:09:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdio.h>
# include "../../Libft/libft.h"
# include <math.h>
# ifdef __linux__
#  include "../../MLX/minilibx_linux/mlx.h"
# else
#  include "../../MLX/minilibx_ogl/mlx.h"
# endif

# define W_KEY	13
# define S_KEY	1
# define UP_KEY	126
# define DOWN_KEY	125
# define RIGHT_KEY	124
# define LEFT_KEY	123
# define ESC	53


typedef struct s_v3 {
	double	x;
	double	y;
	double	z;
}t_v3;

typedef struct s_cam {
	t_v3	pos;
	t_v3	normal;
	double	fov;
}t_cam;

typedef struct s_ray {
	t_v3	origin;
	t_v3	direction;
}t_ray;

typedef struct s_sphere {
	t_v3	pos;
	double	radius;
	int		color;
}t_sphere;

typedef struct s_plane{
	t_v3	pos;
	t_v3	normal;
	int		color;
}t_plane;

typedef enum e_objs
{
    SPHERE,
    PLANE,
} t_objs;

typedef struct s_objects{
	void				*data;
	t_objs				type;
	struct s_objects	*next;
}t_objects;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_cam		*camera;
	t_objects	*objects;
	int			update;
	int			size[2];
}t_vars;




// check_arguments.c
int		check_arguments(int ac, char **av);

// vec3_maths.c
t_v3	subtract_vectors(const t_v3 *A, const t_v3 *B);
void	normalize(t_v3 *vector);
double	dot(const t_v3 *A, const t_v3 *B);
int	cam_normal(t_vars *vars, char a);

// plane.c
t_plane	*set_plane();
int	set_plane_color(t_plane *plane);
double	*hit_plane(t_plane *plane, const t_ray *ray);

// camera.c
t_cam	*set_cam();

// sphere.c
t_sphere	*set_sphere();
int	set_sphere_color(t_sphere *sphere);
double	*hit_sphere(t_sphere *sphere, const t_ray *ray);

// colors.c
int	create_trgb(int t, int r, int g, int b);
int	add_colors(int color1, int color2, int addsub);

// objects.c
t_objects	*load_objects();

#endif