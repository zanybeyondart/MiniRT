/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:33:43 by user              #+#    #+#             */
/*   Updated: 2024/09/15 03:00:45 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_plane	*set_plane(double *xyz, double *normal, double *rgb)
{
	t_plane	*plane;

	plane = ft_smart_malloc(sizeof(t_plane));
	plane->pos.x = xyz[0];
	plane->pos.y = xyz[1];
	plane->pos.z = xyz[2];
	plane->normal.x = normal[0];
	plane->normal.y = normal[1];
	plane->normal.z = normal[2];
	plane->color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	return (plane);
}

int	set_plane_color(t_plane *plane)
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
	if (t[0] <= 0 || (lim_dep && lim_dep[0] && t[0] > lim_dep[0]))
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

t_v3	plane_normal(t_plane *plane)
{
	return (plane->normal);
}
