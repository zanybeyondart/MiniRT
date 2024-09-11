/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:27 by user              #+#    #+#             */
/*   Updated: 2024/09/11 15:25:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_v3	set_cam_normal(t_v3 pixel, t_v3	direction, t_v3 pos)
{
	t_v3	new_pixel;
	double	t;

	t = vec_len(pos, pixel);
	new_pixel = add_vectors(pos, scale_vector(direction, t));
	return (new_pixel);
}

t_v3	set_pixel(int x, int y, t_vars *vars)
{
	double	fov_coeff;
	double	aspect_ratio;
	double	p_x;
	double	p_y;

	fov_coeff = tan((double)vars->camera->fov / 2 * M_PI / 180);
	aspect_ratio = (double)vars->size[0] / (double)vars->size[1];
	p_x = (2 * (x + 0.5) / (double)vars->size[0] - 1)
		* aspect_ratio * fov_coeff;
	p_y = (1 - 2 * (y + 0.5) / (double)vars->size[1]) * fov_coeff;
	return (create_v3(p_x, p_y, 1));
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

void set_size(t_vars *vars)
{
	if (vars->mode == 1)
	{
		vars->size[0] = WIDTH;
		vars->size[1] = HEIGHT;
	}
	else
	{
		vars->size[0] = WIDTH_LD;
		vars->size[1] = HEIGHT_LD;
	}
}

void	scale_image(t_vars *vars)
{
	int	x[2];
	int	y[2];

	y[0] = 0;
	while (y[0] < HEIGHT_LD)
	{
		x[0] = 0;
		while (x[0] < WIDTH_LD)
		{
		y[1] = 0;
			while (y[1] < HEIGHT / HEIGHT_LD)
			{
				x[1] = 0;
				while (x[1] < WIDTH / WIDTH_LD)
				{
					mlx_pixel_put(vars->mlx, vars->win,
						x[0] * WIDTH / WIDTH_LD + x[1],
						y[0] * HEIGHT / HEIGHT_LD + y[1],
						store_render(0, x[0], y[0], 0));
				x[1]++;
				}
		y[1]++;
			}
		x[0]++;
		}
	y[0]++;
	}
}

int	render(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	set_size(vars);
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
		if (vars->mode == 1)
			anti_alias(vars);
		else
		{
			scale_image(vars);
			if (vars->ui->active)
				mlx_put_image_to_window(vars->mlx, vars->win,
				vars->ui->overlay.img, 0, 0);
		}
	}
	mlx_do_sync(vars->mlx);
	return (1);
}
