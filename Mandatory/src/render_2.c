/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:27 by user              #+#    #+#             */
/*   Updated: 2024/09/15 03:04:19 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	render(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	if (vars->update == 1 && set_size(vars))
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
			scale_image(vars);
	}
	mlx_do_sync(vars->mlx);
	return (1);
}

int	low_res_render(t_objects *obj, t_ray ray, int color, double *lim_dep)
{
	double		*closest;
	double		*new;
	t_objects	*closest_obj;

	closest = NULL;
	new = NULL;
	closest_obj = NULL;
	while (obj)
	{
		new = hit_object(obj, &ray, lim_dep);
		if ((new && closest == NULL) || (new && closest && new[0] < closest[0]))
		{
			if (closest)
				free(closest);
			closest = new;
			closest_obj = obj;
		}
		else if (new)
			free(new);
		obj = obj->next;
	}
	if (closest)
		color = data_color(closest_obj);
	return (color);
}

void	scale_image_2(t_vars *vars, int *x, int *y)
{
	mlx_pixel_put(vars->mlx, vars->win,
		x[0] * WIDTH / WIDTH_LD + x[1],
		y[0] * HEIGHT / HEIGHT_LD + y[1],
		store_render(0, x[0], y[0], 0));
}
