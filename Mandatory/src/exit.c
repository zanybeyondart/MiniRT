/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:52:41 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/15 01:00:10 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_objects(t_objects *obj)
{
	if (obj)
	{
		if (obj->next)
			free_objects(obj->next);
		if (obj->data)
			free(obj->data);
		free(obj);
	}
}

void	free_program(t_vars *vars)
{
	if (vars->camera)
		free(vars->camera);
	if (vars->objects)
		free_objects(vars->objects);
	free(vars);
}

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_program(vars);
	exit(0);
}
