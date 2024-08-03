/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/07/28 22:11:54 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_cylinder	*set_cylinder(double x, double y, double z, int color)
{
	t_cylinder	*cylinder;

	cylinder = ft_smart_malloc(sizeof(t_cylinder));
	cylinder->pos.x = x;
	cylinder->pos.y = y;
	cylinder->pos.z = z;
	cylinder->normal.x = 1;
	cylinder->normal.y = 1;
	cylinder->normal.z = 0;
	normalize(&cylinder->normal);
	cylinder->radius = 1;
	cylinder->height = 5;
	cylinder->color = color;
	return (cylinder);
}

int	set_cylinder_color(t_cylinder *cylinder, double *t)
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

int	is_in_bounds(t_v3 hit_point, t_cylinder *cylinder, const t_ray *ray)
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
