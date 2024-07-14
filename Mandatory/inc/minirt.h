/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:03:29 by user              #+#    #+#             */
/*   Updated: 2024/07/14 22:38:24 by zvakil           ###   ########.fr       */
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
	double	fov;
}t_cam;

typedef struct s_ray {
	t_v3	origin;
	t_v3	direction;
}t_ray;

typedef struct s_sphere {
	t_v3	pos;
	double	radius;
	t_v3	color;
}t_sphere;

typedef struct s_plane{
	t_v3	pos;
	t_v3	normal;
	t_v3	color;
}t_plane;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_cam		*camera;
	t_sphere	*sphere;
	t_plane		*plane;
	int			update;
}t_vars;

// check_arguments.c
int		check_arguments(int ac, char **av);

// vec3_maths.c
t_v3	subtract_vectors(const t_v3 *A, const t_v3 *B);
void	normalize(t_v3 *vector);
double	dot(const t_v3 *A, const t_v3 *B);


#endif