/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:46:42 by user              #+#    #+#             */
/*   Updated: 2024/08/08 12:13:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_cam	*set_cam()
{
	t_cam	*camera;

	camera = ft_smart_malloc(sizeof(t_cam));
	camera->pos.x = 0;
	camera->pos.y = 0;
	camera->pos.z = 0;
	camera->normal.x = 0;
	camera->normal.y = 0;
	camera->normal.z = -1;
	camera->fov = 90;
	return (camera);
}
