/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:55:11 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/11 15:25:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	math_vector_xyz(t_v3 *a, t_v3 *b, int as)
{
	if (as == 0)
	{
		a->x += b->x;
		a->y += b->y;
		a->z += b->z;
	}
	if (as == 1)
	{
		a->x -= b->x;
		a->y -= b->y;
		a->z -= b->z;
	}
}

void	edit_controls(int keycode, t_vars *vars)
{
	if (keycode == W_KEY)
		math_vector_xyz(&vars->camera->pos, &vars->camera->up, 0);
	if (keycode == S_KEY)
		math_vector_xyz(&vars->camera->pos, &vars->camera->up, 1);
	if (keycode == UP_KEY)
		math_vector_xyz(&vars->camera->pos, &vars->camera->normal, 0);
	if (keycode == DOWN_KEY)
		math_vector_xyz(&vars->camera->pos, &vars->camera->normal, 1);
	if (keycode == RIGHT_KEY)
		math_vector_xyz(&vars->camera->pos, &vars->camera->right, 0);
	if (keycode == LEFT_KEY)
		math_vector_xyz(&vars->camera->pos, &vars->camera->right, 1);
	vars->update = 1;
}

int	events(int keycode, t_vars *vars)
{
	if (keycode == F1)
		vars->mode = 0;
	if (keycode == F2)
	{
		vars->mode = 1;
		vars->update = 1;
	}
	if (keycode == P)
	{
		if (vars->ui->active)
			vars->ui->active = 0;
		else
			vars->ui->active = 1;
	}
	if (vars->mode == 0)
		edit_controls(keycode, vars);
	if (keycode == ESC)
		quit(vars);
	return (0);
}
