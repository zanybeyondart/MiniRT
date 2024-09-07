/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:55:11 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/03 19:48:22 by zvakil           ###   ########.fr       */
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
}

int	events(int keycode, t_vars *vars)
{
	if (keycode == E)
		vars->mode = 0;
	if (keycode == R)
		vars->mode = 1;
	if (vars->mode == 0)
		edit_controls(keycode, vars);
	if (keycode == ESC)
		quit(vars);
	vars->update = 1;
	return (0);
}
