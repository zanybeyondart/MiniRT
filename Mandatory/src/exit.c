/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:52:41 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/11 14:47:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_objects(t_objects *obj)
{
	if (obj->next)
		free_objects(obj->next);
	free(obj->data);
	free(obj);
}

void	free_program(t_vars *vars)
{
	free(vars->camera);
	free(vars->ui);
	free_objects(vars->objects);
	free(vars);
}

int	quit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_program(vars);
	exit(0);
}
