/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:26:34 by zanybeyonda       #+#    #+#             */
/*   Updated: 2024/08/03 13:06:36 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	check_cap_2(t_cylinder *cylinder, const t_ray *ray, t_v3 point)
{
	t_v3	intersection_point;
	double	t;

	t = dot(subtract_vectors(ray->origin, point), cylinder->normal)
		/ dot(ray->direction, cylinder->normal);
	if (t < 0)
		return (0);
	intersection_point = add_vectors(ray->origin,
			scale_vector(ray->direction, t));
	if (dot(subtract_vectors(point, intersection_point),
			subtract_vectors(point, intersection_point))
		<= cylinder->radius * cylinder->radius)
		return (t);
	return (0);
}

double	*check_cap(t_cylinder *cylinder, const t_ray *ray)
{
	double	bot;
	double	top;
	double	*t;
	t_v3	top_point;
	double	closest;

	top_point = add_vectors(cylinder->pos,
			scale_vector(cylinder->normal, cylinder->height));
	bot = check_cap_2(cylinder, ray, cylinder->pos);
	top = check_cap_2(cylinder, ray, top_point);
	closest = min_double(bot, top);
	if (closest <= 0)
		return (NULL);
	t = ft_smart_malloc(sizeof(double) * 2);
	t[0] = closest;
	t[1] = closest;
	return (t);
}

double	*cylinder_body(t_cylinder *cylinder, const t_ray *ray, double *lim_dep)
{
	t_v3	cal_a[2];
	double	*t;

	cal_a[1] = subtract_vectors(scale_vector(cylinder->normal,
				dot(ray->direction, cylinder->normal)), ray->direction);
	cal_a[0] = subtract_vectors(scale_vector(cylinder->normal,
				dot(subtract_vectors(cylinder->pos, ray->origin),
					cylinder->normal)),
			subtract_vectors(cylinder->pos, ray->origin));
	t = solve_quadratic_eq(dot(cal_a[1], cal_a[1]),
			2 * dot(cal_a[1], cal_a[0]), dot(cal_a[0], cal_a[0])
			- (cylinder->radius * cylinder->radius), lim_dep);
	return (t);
}

double	*hit_cylinder(t_cylinder *cylinder, const t_ray *ray, double *lim_dep)
{
	double	*t;
	double	*t_cap;

	t = cylinder_body(cylinder, ray, lim_dep);
	t_cap = check_cap(cylinder, ray);
	if (t)
	{
		if (t && is_in_bounds(hit_cord(ray, t), cylinder, ray))
		{
			if (t_cap)
			{
				t[0] = min_double(t_cap[0], t[0]);
				free(t_cap);
			}
			return (t);
		}
		free(t);
	}
	if (t_cap)
	{
		if ((lim_dep[0] && t_cap[0] < lim_dep[0]) || (t_cap[0] > 0))
			return (t_cap);
		free (t_cap);
	}
	return (NULL);
}
