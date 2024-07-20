/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:55:11 by zvakil            #+#    #+#             */
/*   Updated: 2024/07/20 17:55:38 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	events(int keycode, t_vars *vars)
{
	if (keycode == W_KEY)
		vars->camera->pos.y += 1;
	if (keycode == S_KEY)
		vars->camera->pos.y -= 1;
	if (keycode == UP_KEY)
		vars->camera->pos.z -= 1;
	if (keycode == DOWN_KEY)
		vars->camera->pos.z += 1;
	if (keycode == RIGHT_KEY)
		vars->camera->pos.x += 1;
	if (keycode == LEFT_KEY)
		vars->camera->pos.x -= 1;
	if (keycode == ESC)
		quit(vars);
	vars->update = 1;
	return (0);
}
