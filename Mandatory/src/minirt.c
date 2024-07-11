/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:59:18 by user              #+#    #+#             */
/*   Updated: 2024/07/11 18:09:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <math.h>

typedef struct s_v3 {
	double	x;
	double y;
	double z;
}t_v3;

typedef struct s_sphere {
	double	x;
	double y;
	double z;
	double	radius;
}t_sphere;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_v3		*camera;
	t_sphere	*sphere;
}t_vars;

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int intersect(t_vars *vars, int x, int y)
{
	double distance;

	distance = sqrt(pow(vars->sphere->x - vars->camera->x, 2) + pow(vars->sphere->y - vars->camera->y, 2) + pow(vars->sphere->z - vars->camera->z, 2));
	if ()
}

int	render(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < 500)
		{
			// if (intersect(vars, i, j))
			// {
				
			// }
			mlx_pixel_put(vars->mlx, vars->win, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_do_sync(vars->mlx);
	return (1);
}

int main (int ac, char **av)
{
	t_vars vars;
	t_v3	camera;
	t_sphere sphere;
	
	camera.x = 0;
	camera.y = 10;
	camera.z = 0;
	sphere.x = 0;
	sphere.y = 10;
	sphere.z = 50;
	sphere.radius = 5;
	vars.camera = &camera;
	vars.sphere = &sphere;
	// if (check_arguments(ac, av))
	// 	return (1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "HELLO");
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_hook(vars.win, 17, 0, quit, &vars);
	mlx_loop(vars.mlx);
	return (0);
}