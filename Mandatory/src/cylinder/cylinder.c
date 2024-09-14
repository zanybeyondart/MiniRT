/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/09/15 03:02:15 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_cylinder	*set_cylinder(t_v3 pos, t_v3 normal, int color, double *rh)
{
	t_cylinder	*cylinder;

	cylinder = ft_smart_malloc(sizeof(t_cylinder));
	cylinder->pos = pos;
	cylinder->normal = normal;
	normalize(&cylinder->normal);
	cylinder->radius = rh[0] / 2;
	cylinder->height = rh[1];
	cylinder->color = color;
	return (cylinder);
}

int	set_cylinder_color(t_cylinder *cylinder)
{
	return (cylinder->color);
}

t_v3	hit_cord(const t_ray *ray, double *t)
{
	t_v3	hit_point;

	hit_point.x = ray->origin.x + ray->direction.x * t[0];
	hit_point.y = ray->origin.y + ray->direction.y * t[0];
	hit_point.z = ray->origin.z + ray->direction.z * t[0];
	return (hit_point);
}

t_ray	cylinder_hitray(t_cylinder *cylinder, double *t, t_ray *ray)
{
	t_v3	hit_point;
	t_v3	n;
	t_v3	cylinder_origin;
	t_ray	final_ray;

	hit_point.x = ray->origin.x + ray->direction.x * t[0];
	hit_point.y = ray->origin.y + ray->direction.y * t[0];
	hit_point.z = ray->origin.z + ray->direction.z * t[0];
	cylinder_origin.x = cylinder->pos.x;
	cylinder_origin.y = cylinder->pos.y;
	cylinder_origin.z = hit_point.z;
	n = subtract_vectors(hit_point, cylinder_origin);
	normalize(&n);
	final_ray.origin = hit_point;
	final_ray.direction = n;
	return (final_ray);
}

int	is_in_bounds(t_v3 hit_point, t_cylinder *cylinder)
{
	t_v3	p1;
	t_v3	p2;
	t_v3	other_end;

	other_end = add_vectors(cylinder->pos,
			scale_vector(cylinder->normal, cylinder->height));
	p1 = subtract_vectors(cylinder->pos, hit_point);
	p2 = subtract_vectors(other_end, hit_point);
	return (dot(cylinder->normal, p1) > 0 && dot(cylinder->normal, p2) < 0);
}
