/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:46:42 by user              #+#    #+#             */
/*   Updated: 2024/07/22 01:36:24 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_cam	*set_cam()
{
	t_cam	*camera;

	camera = ft_smart_malloc(sizeof(t_cam));
	camera->pos.x = 0;
	camera->pos.y = 1;
	camera->pos.z = 3;
	camera->normal.x = 0;
	camera->normal.y = 1;
	camera->normal.z = 0;
	return (camera);
}
