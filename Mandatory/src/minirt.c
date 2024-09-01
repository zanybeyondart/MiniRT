/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:59:18 by user              #+#    #+#             */
/*   Updated: 2024/08/31 12:51:02 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	intersect(t_vars *vars, t_v3 pixel)
{
	t_v3		ray_d;
	t_ray		ray;
	double		lim_dep[2];
	int			color;
	t_matrix	cam_mat;

	cam_mat = look_at(vars->camera->pos, vars->camera->normal, vars->camera);
	ray.origin = multiply_by_matrix(create_v3(0, 0, 0), cam_mat);
	ray_d = multiply_by_matrix(pixel, cam_mat);
	ray.direction = subtract_vectors(ray.origin, ray_d);
	normalize(&ray.direction);
	lim_dep[0] = 0;
	lim_dep[1] = 0;
	color = ray_trace(vars->objects, ray,
			create_trgb(0, 0, 0, 0), lim_dep);
	return (color);
}

int	main(int ac, char **av)
{
	t_vars		*vars;

	check_arguments(ac, av);
	vars = ft_smart_malloc(sizeof(t_vars));
	vars->camera = set_cam();
	vars->objects = load_objects();
	vars->update = 1;
	vars->mlx = mlx_init();
	vars->size[0] = WIDTH;
	vars->size[1] = HEIGHT;
	vars->win = mlx_new_window(vars->mlx, vars->size[0],
			vars->size[1], "HELLO");
	mlx_loop_hook(vars->mlx, render, vars);
	mlx_hook(vars->win, 2, (1L << 0), events, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	quit(vars);
	return (0);
}
