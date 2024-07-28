/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:46:42 by user              #+#    #+#             */
/*   Updated: 2024/07/28 05:27:29 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_cam	*set_cam()
{
	t_cam	*camera;

	camera = ft_smart_malloc(sizeof(t_cam));
	camera->pos.x = 0;
	camera->pos.y = 1;
	camera->pos.z = 0;
	camera->normal.x = 0;
	camera->normal.y = 1;
	camera->normal.z = 0;
	return (camera);
}

int	cam_normal(t_vars *vars, char a)
{
	if (a == 'x')
	{
		if (vars->camera->normal.x >= 0)
			return (1);
		else
			return (-1);
	}
	else if (a == 'y')
	{
		if (vars->camera->normal.y >= 0)
			return (1);
		else
			return (-1);
	}
	else
	{
		if (vars->camera->normal.z >= 0)
			return (1);
		else
			return (-1);
	}
}
