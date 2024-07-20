/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:59:18 by user              #+#    #+#             */
/*   Updated: 2024/07/20 20:55:37 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ray_trace(t_objects *obj, t_ray *ray)
{
	int		color;
	double	*closest;
	double	*new;
	t_v3	*normal;

	closest = NULL;
	new = NULL;
	color = create_trgb(0, 160, 32, 240);
	while (obj)
	{
		if (obj->type == SPHERE)
			new = hit_sphere(obj->data, ray);
		else if (obj->type == PLANE)
			new = hit_plane(obj->data, ray);
		if (new != NULL)
		{
			if (closest == NULL || (new[0] < closest[0]))
			{
				if (closest)
					free(closest);
				closest = new;
				if (obj->type == SPHERE)
					color = sphere_normal(&ray->origin, closest, &ray->direction, obj->data);
				else if (obj->type == PLANE)
					color = plane_normal(obj->data);
			}
			else
				free(new);
		}
		obj = obj->next;
	}
	if (closest)
		free(closest);
	return (color);
}

int	intersect(t_vars *vars, t_v3 pixel)
{
	t_v3	ray_d;
	t_ray	ray;

	ray.origin = vars->camera->pos;
	ray_d = subtract_vectors(&vars->camera->pos, &pixel);
	ray.direction = ray_d;
	normalize(&ray.direction);
	return (ray_trace(vars->objects, &ray));
}

t_v3	set_pixel(int x, int y, t_vars *vars)
{
	t_v3	pixel_position;
	double	fov_radians;
	double	viewport_height;
	double	viewport_width;
	double	uv[2];

	fov_radians = (90.0 * M_PI) / 180.0;
	viewport_height = 2.0 * tan(fov_radians / 2.0) * (1);
	viewport_width = (viewport_height) * 1;
	uv[0] = (double)(x - vars->size[0] / 2)
		/ ((double) vars->size[0] / 2) * (viewport_width / 2);
	uv[1] = (double)(vars->size[1] / 2 - y)
		/ ((double) vars->size[1] / 2) * (viewport_height / 2);
	pixel_position.x = vars->camera->pos.x + uv[0];
	pixel_position.y = vars->camera->pos.y + uv[1];
	pixel_position.z = vars->camera->pos.z - 1.0;
	return (pixel_position);
}

int	render(t_vars *vars)
{
	int		i;
	int		j;
	t_v3	pixel;
	int		color;

	i = 0;
	if (vars->update == 1)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->update = 0;
		while (i < vars->size[0] && vars->update == 0)
		{
			j = 0;
			while (j < vars->size[1] && vars->update == 0)
			{
				color = intersect(vars, pixel);
				pixel = set_pixel(i, j, vars);
				mlx_pixel_put(vars->mlx, vars->win, i, j,
					color);
				if (i > 1 && j > 1 && i < WIDTH - 2 && j < HEIGHT - 2)
					store_render(1, i, j, color);
				j++;
			}
			i++;
		}
		anti_alias(vars);
	}
	mlx_do_sync(vars->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars		*vars;

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
	mlx_hook(vars->win, 2, 0, events, vars);
	mlx_hook(vars->win, 17, 0, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
