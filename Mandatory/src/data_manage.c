/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:43:56 by user              #+#    #+#             */
/*   Updated: 2024/07/26 22:39:25 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	data_color(t_objects *obj, double *t)
{
	if (obj->type == SPHERE)
		return (set_sphere_color(obj->data, t));
	else if (obj->type == PLANE)
		return (set_plane_color(obj->data, t));
	return (0);
}

double	*hit_object(t_objects *obj, t_ray *ray, double *lim_dep)
{
	double	*new;

	new = NULL;
	if (obj->type == SPHERE)
		new = hit_sphere(obj->data, ray, lim_dep);
	else if (obj->type == PLANE)
		new = hit_plane(obj->data, ray, lim_dep);
	return (new);
}
