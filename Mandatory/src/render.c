/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:27 by user              #+#    #+#             */
/*   Updated: 2024/07/22 14:25:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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

void	render_pixel(t_vars *vars, int i, int j)
{
	t_v3	pixel;
	int		color;

	pixel = set_pixel(i, j, vars);
	color = intersect(vars, pixel);
	mlx_pixel_put(vars->mlx, vars->win, i, j, color);
	store_render(1, i, j, color);
}

int	render(t_vars *vars)
{
	int		i;
	int		j;

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
				render_pixel(vars, i, j);
				j++;
			}
			i++;
		}
		anti_alias(vars);
	}
	mlx_do_sync(vars->mlx);
	return (1);
}
