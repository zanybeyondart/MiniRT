/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:59:18 by user              #+#    #+#             */
/*   Updated: 2024/07/26 22:19:08 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	intersect(t_vars *vars, t_v3 pixel)
{
	t_v3	ray_d;
	t_ray	ray;
	double	lim_dep[2];

	ray.origin = vars->camera->pos;
	ray_d = subtract_vectors(&vars->camera->pos, &pixel);
	ray.direction = ray_d;
	normalize(&ray.direction);
	lim_dep[0] = 0;
	lim_dep[1] = 0;
	return (ray_trace(vars->objects, ray, create_trgb(0, 0, 0, 0),
			lim_dep));
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
