/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_maths_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:45:35 by zanybeyonda       #+#    #+#             */
/*   Updated: 2024/08/25 20:21:37 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_v3	cross(const t_v3 a, const t_v3 b)
{
	t_v3	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_v3	scale_vector(const t_v3 v, double scale)
{
	t_v3	result;

	result.x = v.x * scale;
	result.y = v.y * scale;
	result.z = v.z * scale;
	return (result);
}

t_v3	divide_vector(const t_v3 v, double div)
{
	t_v3	result;

	result.x = v.x / div;
	result.y = v.y / div;
	result.z = v.z / div;
	return (result);
}

double	vec_len(const t_v3 a, const t_v3 b)
{
	return (sqrt(pow((b.x - a.x), 2)
			+ pow((b.y - a.y), 2) + pow((b.z - a.z), 2)));
}

double	*solve_quadratic_eq(double a, double b, double c, double *lim_dep)
{
	double	discriminant;
	double	*t;

	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (NULL);
	t = ft_smart_malloc(sizeof(double) * 2);
	t[0] = ((-b + sqrt(discriminant)) / (2 * a));
	t[1] = ((-b - sqrt(discriminant)) / (2 * a));
	t[0] = min_double(t[0], t[1]);
	if ((lim_dep && lim_dep[0] && t[0] > lim_dep[0]) || (t[0] <= 0))
	{
		free (t);
		return (NULL);
	}
	return (t);
}

t_v3	ray_equation(t_v3 o, t_v3 td)
{
	return (add_vectors(o, td));
}
