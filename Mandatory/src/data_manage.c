/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:43:56 by user              #+#    #+#             */
/*   Updated: 2024/07/22 16:53:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	data_color(t_objects *obj)
{
	if (obj->type == SPHERE)
		return (set_sphere_color(obj->data));
	else if (obj->type == PLANE)
		return (set_plane_color(obj->data));
}
