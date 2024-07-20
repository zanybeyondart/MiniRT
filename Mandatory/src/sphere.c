/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/07/20 17:57:44 by zvakil           ###   ########.fr       */
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
	sphere->color = create_trgb(0, 0, 215, 0);
	return (sphere);
}

int	set_sphere_color(t_sphere *sphere)
{
	return (sphere->color);
}

int	sphere_normal(t_v3 *ray_o, double *t, t_v3 *ray_d, t_sphere *sphere)
{
	t_v3	n;
	t_v3	t_ray;

	t_ray.x = ray_o->x + ray_d->x * t[0];
	t_ray.y = ray_o->y + ray_d->y * t[0];
	t_ray.z = ray_o->z + ray_d->z * t[0];
	n.x = (t_ray.x - sphere->pos.x) / sphere->radius;
	n.y = (t_ray.y - sphere->pos.y) / sphere->radius;
	n.z = (t_ray.z - sphere->pos.z) / sphere->radius;
	normalize(&n);
	return (create_trgb(0, 127.5 * (n.x + 1),
			127.5 * (n.y + 1), 127.5 * (n.z + 1)));
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
