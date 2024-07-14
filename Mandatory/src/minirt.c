/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:59:18 by user              #+#    #+#             */
/*   Updated: 2024/07/14 22:06:17 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	hit_sphere(t_vars *vars, const t_ray ray)
{
	t_v3	oc;
	float	a;
	float	b;
	float	c;
	float	intersect;

	oc = subtract_vectors(&ray.origin, &vars->sphere->pos);
	a = dot(&ray.direction, &ray.direction);
	b = 2.0 * dot(&oc, &ray.direction);
	c = dot(&oc, &oc) - vars->sphere->radius * vars->sphere->radius;
	intersect = b * b - 4 * a * c;
	return (intersect > 0);
}

// int	hit_plane(t_vars *vars, t_ray ray)
// {
// 	double	t;
// 	double	denom;
// 	t_v3	intersect;

// 	t = 0;
// 	denom = dot(&vars->plane->normal, &ray.direction);
// 	if (denom > 0)
// 	{
// 		intersect = subtract_vectors(&vars->plane->pos, &ray.origin);
// 		t = dot(&intersect, &vars->plane->normal) / denom;
// 		if (t >= 0)
// 			return (1);
// 	}
// 	return (0);
// }

int hit_plane(t_vars *vars, const t_ray ray)
{
    double Vd, V0, t, dee;

    Vd = dot(&vars->plane->normal, &ray.direction);

    if (fabs(Vd) < 1e-6)
        return 0;
	dee = -(vars->plane->pos.x + vars->plane->pos.y + vars->plane->pos.z);
    V0 = -(dot(&vars->plane->normal, &ray.origin) + dee);
    t = V0 / Vd;
    if (t < 0)
        return 0;

   return 1;
}

int	intersect(t_vars *vars, t_v3 pixel)
{
	t_v3	ray_d;
	t_ray	ray;

	ray.origin = vars->camera->pos;
	ray_d = subtract_vectors(&vars->camera->pos, &pixel);
	normalize(&ray_d);
	ray.direction = ray_d;
	if (hit_sphere(vars, ray))
		return (0x00FF0000);
	if (hit_plane(vars, ray))
		return (0x000000FF);
	else
		return (0x0000FF00);
}

t_v3	set_pixel(int x, int y, t_vars *vars)
{
	t_v3	pixel_position;
	double	fov_radians;
	double	viewport_height;
	double	viewport_width;
	double	uv[2];

	fov_radians = (90 * M_PI) / 180.0;
	viewport_height = 2.0 * tan(fov_radians / 2.0) * (1);
	viewport_width = (viewport_height) * 1;
	uv[0] = (double)(x - 500 / 2) / (double) 500 / 2 * (viewport_width / 2);
	uv[1] = (double)(500 / 2 - y) / (double) 500 / 2 * (viewport_height / 2);
	pixel_position.x = vars->camera->pos.x + uv[0];
	pixel_position.y = vars->camera->pos.y + uv[1];
	pixel_position.z = vars->camera->pos.z + 1.0;
	return (pixel_position);
}

int	render(t_vars *vars)
{
	int		i;
	int		j;
	t_v3	pixel;

	i = 0;
	if (vars->update == 1)
	{
		vars->update = 0;
		while (i < 500 && vars->update == 0)
		{
			j = 0;
			while (j < 500 && vars->update == 0)
			{
				pixel = set_pixel(i, j, vars);
				mlx_pixel_put(vars->mlx, vars->win, i, j,
					intersect(vars, pixel));
				j++;
			}
			i++;
		}
	}
	mlx_do_sync(vars->mlx);
	return (1);
}

int	events(int keycode, t_vars *vars)
{
	if (keycode == W_KEY)
		vars->camera->pos.y += 1;
	if (keycode == S_KEY)
		vars->camera->pos.y -= 1;
	if (keycode == UP_KEY)
		vars->camera->pos.z += 1;
	if (keycode == DOWN_KEY)
		vars->camera->pos.z -= 1;
	if (keycode == RIGHT_KEY)
		vars->camera->pos.x += 1;
	if (keycode == LEFT_KEY)
		vars->camera->pos.x -= 1;
	if (keycode == ESC)
		quit(vars);
	vars->update = 1;
	return (0);
}

int	main(int ac, char **av)
{
	t_vars		vars;
	t_cam		camera;
	t_sphere	sphere;
	t_plane		plane;

	plane.pos.x = 0;
	plane.pos.y = 10;
	plane.pos.z = 0;
	plane.normal.x = 0;
	plane.normal.y = -1;
	plane.normal.z = 0;
	camera.pos.x = 0;
	camera.pos.y = 0;
	camera.pos.z = 0;
	sphere.pos.x = 0;
	sphere.pos.y = 0;
	sphere.pos.z = 30;
	sphere.radius = 3;
	vars.camera = &camera;
	vars.sphere = &sphere;
	vars.plane = &plane;
	vars.update = 1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "HELLO");
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_hook(vars.win, 2, 0, events, &vars);
	mlx_hook(vars.win, 17, 0, quit, &vars);
	mlx_loop(vars.mlx);
	return (0);
}