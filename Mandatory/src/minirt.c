/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:59:18 by user              #+#    #+#             */
/*   Updated: 2024/07/17 17:35:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_objects(t_objects *obj)
{
	if (obj->next)
		free_objects(obj->next);
	free(obj->data);
	free(obj);
}

void	free_program(t_vars *vars)
{
	free(vars->camera);
	free_objects(vars->objects);
	free(vars);
}

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_program(vars);
	exit(0);
}

int	hit_sphere(t_sphere *sphere, const t_ray *ray)
{
	t_v3	oc;
	float	a;
	float	b;
	float	c;
	float	intersect;

	oc = subtract_vectors(&ray->origin, &sphere->pos);
	a = dot(&ray->direction, &ray->direction);
	b = 2.0 * dot(&oc, &ray->direction);
	c = dot(&oc, &oc) - sphere->radius * sphere->radius;
	intersect = b * b - 4 * a * c;
	
	if (intersect > 0)
		return (sphere->color);
	else
		return (create_trgb(0, 160, 32, 240));
}

int hit_plane(t_plane *plane, const t_ray *ray)
{
    double Vd, V0, t, dee;

    Vd = dot(&plane->normal, &ray->direction);

    if (fabs(Vd) < 1e-6)
        return 0;
	dee = -(plane->pos.x + plane->pos.y + plane->pos.z);
    V0 = -(dot(&plane->normal, &ray->origin) + dee);
    t = V0 / Vd;
    if (t < 0)
        return (create_trgb(0, 160, 32, 240));

   return (plane->color);
}

int	ray_trace(t_objects *obj, t_ray *ray)
{
	int	color;
	
	color = create_trgb(0, 160, 32, 240);
	while (obj)
	{
		if (obj->type == SPHERE)
			color = hit_sphere(obj->data, ray);
		else if (obj->type == PLANE)
			color = hit_plane(obj->data, ray);
		obj = obj->next;
	}
	return (color);
}

int	intersect(t_vars *vars, t_v3 pixel)
{
	t_v3	ray_d;
	t_ray	ray;

	ray.origin = vars->camera->pos;
	ray_d = subtract_vectors(&vars->camera->pos, &pixel);
	normalize(&ray_d);
	ray.direction = ray_d;
	return (ray_trace(vars->objects, &ray));
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
		mlx_clear_window(vars->mlx, vars->win);
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
	t_vars		*vars;

	vars = ft_smart_malloc(sizeof(t_vars));
	vars->camera = set_cam();
	vars->objects = load_objects();
	vars->update = 1;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 500, 500, "HELLO");
	mlx_loop_hook(vars->mlx, render, vars);
	mlx_hook(vars->win, 2, 0, events, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
