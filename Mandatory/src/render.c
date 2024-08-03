/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:27 by user              #+#    #+#             */
/*   Updated: 2024/08/03 13:28:06 by zanybeyonda      ###   ########.fr       */
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

//t_v3	set_pixel(int x, int y, t_vars *vars)
//{
//	t_v3	pixel_position;
//	double	fov_radians;
//	double	viewport_height;
//	double	viewport_width;
//	t_v3	uv;

//	fov_radians = (90.0 * M_PI) / 180.0;
//	viewport_height = 2.0 * tan(fov_radians / 2.0) * (1);
//	viewport_width = (viewport_height) * 1;
//	uv.x = (double)(x - vars->size[0] / 2)
//		/ ((double) vars->size[0] / 2) * (viewport_width / 2);
//	uv.y = (double)(vars->size[1] / 2 - y)
//		/ ((double) vars->size[1] / 2) * (viewport_height / 2);
//	uv.z = 1.0;
//	pixel_position = add_vectors(vars->camera->pos, uv);
//	return (pixel_position);
//}

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
		// anti_alias(vars);
	}
	mlx_do_sync(vars->mlx);
	return (1);
}
