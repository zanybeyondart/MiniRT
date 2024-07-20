/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/07/20 14:54:19 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_sphere	*set_sphere()
{
	t_sphere	*sphere;

	sphere = ft_smart_malloc(sizeof(t_sphere));
	sphere->pos.x = 0;
	sphere->pos.y = 0;
	sphere->pos.z = 10;
	sphere->radius = 1;
	sphere->color = create_trgb(0, 0, 215, 0);
	return (sphere);
}

int	set_sphere_color(t_sphere *sphere)
{
	return (sphere->color);
}

// double	*hit_sphere(t_sphere *sphere, const t_ray *ray)
// {
// 	t_v3	oc;
// 	double	a[3];
// 	double	intersect;
// 	double	*t;

// 	t = ft_smart_malloc(sizeof(double) * 2);
// 	oc = subtract_vectors(&ray->origin, &sphere->pos);
// 	a[0] = dot(&ray->direction, &ray->direction);
// 	a[1] = 2.0 * dot(&oc, &ray->direction);
// 	a[2] = dot(&oc, &oc) - sphere->radius * sphere->radius;
// 	intersect = a[1] * a[1] - 4 * a[0] * a[2];
// 	if (intersect <= 0)
// 	{
// 		free(t);
// 		return (NULL);
// 	}
// 	t[0] = (a[1] + sqrtf(intersect)) / (2 * a[0]);
// 	t[1] = (a[1] - sqrtf(intersect)) / (2 * a[0]);
// 	if (t[0] < 0 && t[1] < 0)
// 	{
// 		free(t);
// 		return (NULL);
// 	}
// 	return (t);
// }

double	*hit_sphere(t_sphere *sphere, const t_ray *ray)
{
	t_v3	oc;
	double	a[3];
	double	intersect;
	double	*t;

	t = ft_smart_malloc(sizeof(double) * 2);
	oc = subtract_vectors(&ray->origin, &sphere->pos);
	a[0] = dot(&ray->direction, &ray->direction);
	a[1] = dot(&oc, &ray->direction);
	a[2] = dot(&oc, &oc) - sphere->radius * sphere->radius;
	intersect = a[1] * a[1] - a[0] * a[2];
	if (intersect <= 0)
	{
		free(t);
		return (NULL);
	}
	t[0] = (a[1] - sqrtf(intersect)) / a[0];
	t[1] = (a[1] + sqrtf(intersect)) / a[0];
	if (t[0] < 0 && t[1] < 0)
	{
		free(t);
		return (NULL);
	}
	return (t);
}
