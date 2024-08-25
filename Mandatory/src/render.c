/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:27 by user              #+#    #+#             */
/*   Updated: 2024/08/25 18:15:07 by zanybeyonda      ###   ########.fr       */
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
