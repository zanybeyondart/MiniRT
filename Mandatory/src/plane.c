/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:33:43 by user              #+#    #+#             */
/*   Updated: 2024/07/28 19:24:07 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_plane	*set_plane()
{
	t_plane	*plane;

	plane = ft_smart_malloc(sizeof(t_plane));
	plane->pos.x = 0;
	plane->pos.y = 0;
	plane->pos.z = 0;
	plane->normal.x = 0;
	plane->normal.y = 1;
	plane->normal.z = 0;
	plane->color = create_trgb(0, 150, 150, 150);
	return (plane);
}

int	set_plane_color(t_plane *plane, double *t)
{
	return (plane->color);
}

double	*hit_plane(t_plane *plane, const t_ray *ray, double *lim_dep)
{
	double	vd;
	double	v0;
	double	*t;
	double	dee;

	vd = dot(plane->normal, ray->direction);
	if (fabs(vd) < 1e-9)
		return (NULL);
	dee = -(plane->pos.x + plane->pos.y + plane->pos.z);
	v0 = -(dot(plane->normal, ray->origin) + dee);
	t = ft_smart_malloc(sizeof(double) * 2);
	t[0] = v0 / vd;
	t[1] = 0;
	if (t[0] <= 0 || (lim_dep[0] && t[0] > lim_dep[0]))
	{
		free(t);
		return (NULL);
	}
	return (t);
}

t_ray	plane_hitray(t_plane *plane, double *t, t_ray *ray)
{
	t_v3		rayt;
	t_ray		final_ray;

	rayt.x = ray->origin.x + ray->direction.x * t[0];
	rayt.y = ray->origin.y + ray->direction.y * t[0];
	rayt.z = ray->origin.z + ray->direction.z * t[0];
	if (ray->origin.y <= plane->pos.y)
	{
		final_ray.direction = plane->normal;
		final_ray.direction.y *= -1.0;
	}
	else
		final_ray.direction = plane->normal;
	final_ray.origin = rayt;
	return (final_ray);
}
