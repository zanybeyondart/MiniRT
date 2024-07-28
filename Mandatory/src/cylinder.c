/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/07/28 19:17:38 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_cylinder	*set_cylinder(double x, double y, double z, int color)
{
	t_cylinder	*cylinder;

	cylinder = ft_smart_malloc(sizeof(t_cylinder));
	cylinder->pos.x = x;
	cylinder->pos.y = y;
	cylinder->pos.z = z;
	cylinder->normal.x = 0;
	cylinder->normal.y = 1;
	cylinder->normal.z = 0;
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
	n = subtract_vectors(&hit_point, &cylinder_origin);
	normalize(&n);
	final_ray.origin = hit_point;
	final_ray.direction = n;
	return (final_ray);
}

int	is_in_bounds(t_v3 hit_point, t_cylinder *cylinder, const t_ray *ray)
{
	t_v3	p1;
	t_v3	p2;
	t_v3	other_end[2];

	other_end[0] = scale_vector(&cylinder->normal, cylinder->height);
	other_end[1] = add_vectors(&other_end[0], &cylinder->pos);
	p1 = subtract_vectors(&cylinder->pos, &hit_point);
	p2 = subtract_vectors(&other_end[1], &hit_point);
	return (dot(&cylinder->normal, &p1) > 0 && dot(&cylinder->normal, &p2) < 0);
}

//double	*check_cap(t_cylinder *cylinder, t_ray *ray, t_v3 cap_center)
//{
//	double	t;
//	t_v3	intersection_point;
//	t_v3	t_a;

//	t_a = subtract_vectors(&cap_center, &ray->origin);
//	t = dot(&t_a, &cylinder->normal)/ dot(&ray->direction, &cylinder->normal);
//	if (t < 0)
//		return (NULL);
//	intersection_point = add_vectors(&ray->origin, scale_vector(&ray->direction, t));

//	// Check if the intersection point is within the cap's radius
//	if (dot(subtract_vectors(&intersection_point, &cap_center), subtract_vectors(&intersection_point, &cap_center)) <= cylinder->radius * cylinder->radius) {
//	    return t;
//	}

//	return -1;
//}

double	*hit_cylinder(t_cylinder *cylinder, const t_ray *ray, double *lim_dep)
{
	t_v3	cal_a[2];
	t_v3	dlt_p[2];
	t_v3	cal_c;
	double	*t;
	double	*t_cap;

	t = NULL;
	cal_a[0] = scale_vector(&cylinder->normal,
			dot(&ray->direction, &cylinder->normal));
	cal_a[1] = subtract_vectors(&cal_a[0], &ray->direction);
	dlt_p[0] = subtract_vectors(&cylinder->pos, &ray->origin);
	dlt_p[1] = scale_vector(&cylinder->normal,
			dot(&dlt_p[0], &cylinder->normal));
	cal_c = subtract_vectors(&dlt_p[1], &dlt_p[0]);
	t = solve_quadratic_eq(dot(&cal_a[1], &cal_a[1]),
			2 * dot(&cal_a[1], &cal_c), dot(&cal_c, &cal_c)
			- (cylinder->radius * cylinder->radius), lim_dep);
	//t_cap = check_caps();
	if (t && !is_in_bounds(hit_cord(ray, t), cylinder, ray))
	{
		free(t);
		return (NULL);
	}
	return (t);
}

