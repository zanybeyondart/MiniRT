/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:27 by user              #+#    #+#             */
/*   Updated: 2024/09/15 01:00:06 by zvakil           ###   ########.fr       */
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

int	set_size(t_vars *vars)
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
	return (1);
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
					scale_image_2(vars, x, y);
					x[1]++;
				}
				y[1]++;
			}
			x[0]++;
		}
		y[0]++;
	}
}
