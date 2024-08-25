/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:55:11 by zvakil            #+#    #+#             */
/*   Updated: 2024/08/25 11:03:59 by zanybeyonda      ###   ########.fr       */
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
    if (keycode == ESC)
        quit(vars);
    vars->update = 1;
    return (0);
}
