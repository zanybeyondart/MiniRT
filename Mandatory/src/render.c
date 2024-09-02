/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:27 by user              #+#    #+#             */
/*   Updated: 2024/09/02 19:48:07 by zvakil           ###   ########.fr       */
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
					int scale_x = WIDTH / WIDTH_LD;
int scale_y = HEIGHT / HEIGHT_LD;

for (int y = 0; y < HEIGHT_LD; y++) { // Loop over low-res height
    for (int x = 0; x < WIDTH_LD; x++) { // Loop over low-res width
        for (int dy = 0; dy < scale_y; dy++) { // Scale in y-direction
            for (int dx = 0; dx < scale_x; dx++) { // Scale in x-direction
                mlx_pixel_put(vars->mlx, vars->win, x * scale_x + dx, y * scale_y + dy, store_render(0, x, y, 0));
            }
        }
    }
}

		}
	}
	mlx_do_sync(vars->mlx);
	return (1);
}
