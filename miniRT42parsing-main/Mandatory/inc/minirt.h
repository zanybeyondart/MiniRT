/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:03:29 by user              #+#    #+#             */
/*   Updated: 2024/09/13 01:28:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <stdio.h>
# include "../../Libft/libft.h"
# include <math.h>
# include <stdint.h>


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
# endif

// SETTINGS
# define WIDTH	500
# define HEIGHT	500
# define WIDTH_LD 100
# define HEIGHT_LD 100
# define THRESHOLD	1

// DIFFUSE RAY SETTINGS
# define SAMPLES 1
# define DIFFUSE_RAY_LIMIT 1
# define DIFFUSE_RAY_BOUNCES 0

// RANDOM SEED GEN
# define SEED_A 1664525
# define SEED_C 1013904223
# define SEED_M 4294967296

typedef struct s_v3  //defines 3d vector
{
	double	x; //position
	double	y; //directions
	double	z; //normals
}	t_v3;

typedef struct s_cam //represents camera in 3d scene 
{ 
	t_v3	pos;     //represents x,y,z (3d vector struct)
	t_v3	normal;  //3D normalized orientation vector
	t_v3	up;      //camera is up (not described in the input, but useful for camera operations)
	t_v3	right;	 //camera is right 
	double	fov;	 //field of view 
}	t_cam;

typedef struct s_matrix //For transformation purposes (rotation, scaling, translation)
{
	double	d[4][4]; 
}	t_matrix;

typedef struct s_ray //Represents a ray in ray tracing
{
	t_v3	origin;
	t_v3	direction;
}	t_ray;

typedef struct s_sphere //sphere
{
	t_v3	pos;     //represents x,y,z (3d vector struct)
	double	radius;  //We will be given a diameter so we will divide it and store
	int		color;   //RGB colour value with 323 bit integer shifting
}	t_sphere;

typedef struct s_plane //plane
{
	t_v3	pos;	//represents x,y,z (3d vector struct)
	t_v3	normal;	//3D normalized orientation vector
	int		color; 	//RGB colour value with 323 bit integer shifting
}	t_plane;

typedef struct s_cylinder //cylinder
{
	t_v3	pos;	//represents x,y,z (3d vector struct)
	t_v3	normal;	//3D normalized orientation vector
	double	radius; //We will be given a diameter so we will divide it and store
	double	height; //cylinder height
	int		color;	//RGB colour value with 323 bit integer shifting
}	t_cylinder;

typedef enum e_objs
{
	SPHERE,
	PLANE,
	CYLINDER,
	A_LIGHT,
	P_LIGHT,
}	t_objs;

typedef struct s_light //light  AND Ambient -> Represents different light sources in your scene.
{
	double	intensity;	//light brightness ratio
	int		color;		//RGB colour value with 323 bit integer shifting
	t_v3	pos;		//represents x,y,z (3d vector struct)
	t_objs	type;		//Type of the light (for example, point light, area light)
}	t_light;

typedef struct s_objects //A linked list of objects in the scene.
{
	void				*data;	//pointer to the object
	t_objs				type;	//type of the object
	int					id; 	//object ID
	struct s_objects	*next;  //pointer to the next object in the list (next)
}	t_objects;

typedef struct s_vars //Contains global variables for your MiniRT application
{
	void		*mlx;		// Pointer to the MLX library instance (MiniLibX)
	void		*win;		// Pointer to the MLX window,
	t_cam		*camera;	// Pointer to the camera object, which stores the camera's pos, normal, and fov
	t_objects	*objects;	// Pointer to a linked list of all the scene's objects (spheres, planes, etc.)
	int			update;		// A flag (integer) indicating whether the scene needs to be updated
	int			size[2];	// Array representing the size of the window: width and height
	int			mode;		// An integer value representing the current rendering mode (e.g., normal render, wireframe mode, etc.).
}	t_vars;

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


//Zain Functions
t_objects	*add_to_list(t_objects *main, void *data, t_objs type, int id);
int			create_trgb(int t, int r, int g, int b);

#endif
