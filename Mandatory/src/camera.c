/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:46:42 by user              #+#    #+#             */
/*   Updated: 2024/08/25 19:32:34 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_cam	*get_camera(t_cam *cam, int set)
{
	static t_cam	*camera;

	if (set == 1)
		camera = cam;
	return (camera);
}

t_cam	*set_cam()
{
	t_cam	*camera;

	camera = ft_smart_malloc(sizeof(t_cam));
	camera->pos.x = 0;
	camera->pos.y = 0;
	camera->pos.z = 0;
	camera->normal.x = 0;
	camera->normal.y = 0;
	camera->normal.z = 1;
	camera->fov = 90;
	get_camera(camera, 1);
	return (camera);
}
