/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:43:56 by user              #+#    #+#             */
/*   Updated: 2024/08/31 13:01:27 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	*return_type(t_objects	*world, t_objs type)
{
	while (world)
	{
		if (world->type == type)
			return (world->data);
		world = world->next;
	}
	return (NULL);
}

int	data_color(t_objects *obj, double *t)
{
	if (obj == NULL)
		return (0);
	if (obj->type == SPHERE)
		return (set_sphere_color(obj->data, t));
	else if (obj->type == PLANE)
		return (set_plane_color(obj->data, t));
	else if (obj->type == CYLINDER)
		return (set_cylinder_color(obj->data, t));
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
	else if (obj->type == CYLINDER)
		new = hit_cylinder(obj->data, ray, lim_dep);
	return (new);
}
