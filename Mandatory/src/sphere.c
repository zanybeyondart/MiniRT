/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/08/25 17:47:33 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_sphere	*set_sphere(double x, double y, double z, int color)
{
	t_sphere	*sphere;

	sphere = ft_smart_malloc(sizeof(t_sphere));
	sphere->pos.x = x;
	sphere->pos.y = y;
	sphere->pos.z = z;
	sphere->radius = 2;
	sphere->color = color;
	return (sphere);
}

int	set_sphere_color(t_sphere *sphere, double *t)
{
	return (sphere->color);
}

t_ray	sphere_hitray(t_sphere *sphere, double *t, t_ray *ray)
{
	t_v3		n;
	t_v3		rayt;
	t_ray		final_ray;

	rayt.x = ray->origin.x + ray->direction.x * t[0];
	rayt.y = ray->origin.y + ray->direction.y * t[0];
	rayt.z = ray->origin.z + ray->direction.z * t[0];
	n.x = (rayt.x - sphere->pos.x) / sphere->radius;
	n.y = (rayt.y - sphere->pos.y) / sphere->radius;
	n.z = (rayt.z - sphere->pos.z) / sphere->radius;
	normalize(&n);
	final_ray.direction = n;
	final_ray.origin = rayt;
	return (final_ray);
}

double	*hit_sphere(t_sphere *sphere, const t_ray *ray, double *lim_dep)
{
	t_v3	l;
	double	tca;
	double	thc;
	double	d2;
	double	*t;

	l = subtract_vectors(ray->origin, sphere->pos);
	tca = dot(l, ray->direction);
	if (tca < 0)
		return (NULL);
	d2 = dot(l, l) - tca * tca;
	if (d2 > sphere->radius * sphere->radius)
		return (NULL);
	thc = sqrtf(sphere->radius * sphere->radius - d2);
	t = ft_smart_malloc(sizeof(double) * 2);
	t[0] = tca - thc;
	t[1] = tca + thc;
	if (lim_dep && lim_dep[0] && t[0] > lim_dep[0])
	{
		free (t);
		return (NULL);
	}
	return (t);
}

t_v3	sphere_normal_at_point(t_sphere *sphere, t_v3 point)
{
	t_v3	normal;

	normal = subtract_vectors(sphere->pos, point);
	normalize(&normal);
	return (normal);
}
