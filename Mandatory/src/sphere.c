/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/07/22 17:59:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_sphere	*set_sphere()
{
	t_sphere	*sphere;

	sphere = ft_smart_malloc(sizeof(t_sphere));
	sphere->pos.x = 0;
	sphere->pos.y = 0;
	sphere->pos.z = -4;
	sphere->radius = 5;
	sphere->color = create_trgb(0, 244, 0, 0);
	return (sphere);
}

int	set_sphere_color(t_sphere *sphere)
{
	return (sphere->color);
}

int	sphere_normal(t_ray *ray, double *t, t_objects *obj, t_objects *w_objs)
{
	t_v3		n;
	t_v3		rayt;
	t_ray		inter;
	t_sphere	*sphere;

	sphere = obj->data;
	rayt.x = ray->origin.x + ray->direction.x * t[0];
	rayt.y = ray->origin.y + ray->direction.y * t[0];
	rayt.z = ray->origin.z + ray->direction.z * t[0];
	inter.origin = rayt;
	n.x = (rayt.x - sphere->pos.x) / sphere->radius;
	n.y = (rayt.y - sphere->pos.y) / sphere->radius;
	n.z = (rayt.z - sphere->pos.z) / sphere->radius;
	normalize(&n);
	inter.direction = n;
	return (diffuse(&inter, obj, w_objs, 10));
}

double	*hit_sphere(t_sphere *sphere, const t_ray *ray)
{
	t_v3	l;
	double	tca;
	double	thc;
	double	d2;
	double	*t;

	l = subtract_vectors(&ray->origin, &sphere->pos);
	tca = dot(&l, &ray->direction);
	if (tca < 0)
		return (NULL);
	d2 = dot(&l, &l) - tca * tca;
	if (d2 > sphere->radius * sphere->radius)
		return (NULL);
	thc = sqrtf(sphere->radius * sphere->radius - d2);
	t = ft_smart_malloc(sizeof(double) * 2);
	t[0] = tca - thc;
	t[1] = tca + thc;
	return (t);
}
