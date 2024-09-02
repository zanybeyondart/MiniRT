/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:55:11 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/02 19:17:00 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	events(int keycode, t_vars *vars)
{
	 if (keycode == W_KEY) {
        vars->camera->pos.x += vars->camera->up.x;
        vars->camera->pos.y += vars->camera->up.y;
        vars->camera->pos.z += vars->camera->up.z;
    }
    if (keycode == S_KEY) {
        vars->camera->pos.x -= vars->camera->up.x;
        vars->camera->pos.y -= vars->camera->up.y;
        vars->camera->pos.z -= vars->camera->up.z;
    }
    if (keycode == UP_KEY) {
        vars->camera->pos.x += vars->camera->normal.x;
        vars->camera->pos.y += vars->camera->normal.y;
        vars->camera->pos.z += vars->camera->normal.z;
    }
    if (keycode == DOWN_KEY) {
        vars->camera->pos.x -= vars->camera->normal.x;
        vars->camera->pos.y -= vars->camera->normal.y;
        vars->camera->pos.z -= vars->camera->normal.z;
    }
    if (keycode == RIGHT_KEY) {
        vars->camera->pos.x += vars->camera->right.x;
        vars->camera->pos.y += vars->camera->right.y;
        vars->camera->pos.z += vars->camera->right.z;
    }
    if (keycode == LEFT_KEY) {
        vars->camera->pos.x -= vars->camera->right.x;
        vars->camera->pos.y -= vars->camera->right.y;
        vars->camera->pos.z -= vars->camera->right.z;
    }
	if (keycode == E)
		vars->mode = 0;
	if (keycode == R)
		vars->mode = 1;
    if (keycode == ESC)
        quit(vars);
    vars->update = 1;
    return (0);
}
