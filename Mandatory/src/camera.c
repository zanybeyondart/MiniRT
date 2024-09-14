/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:46:42 by user              #+#    #+#             */
/*   Updated: 2024/09/14 15:18:40 by zvakil           ###   ########.fr       */
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

t_cam	*set_cam(double *xyz, double *normal, double fov)
{
	t_cam	*camera;
	t_vars	*vars;

	camera = ft_smart_malloc(sizeof(t_cam));
	camera->pos.x = xyz[0];
	camera->pos.y = xyz[1];
	camera->pos.z = xyz[2];
	camera->normal.x = normal[0];
	camera->normal.y = normal[1];
	camera->normal.z = normal[2];
	camera->fov = fov;
	get_camera(camera, 1);
	return (camera);
}
