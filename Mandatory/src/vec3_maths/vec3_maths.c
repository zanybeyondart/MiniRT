/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_maths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:05:25 by zvakil            #+#    #+#             */
/*   Updated: 2024/07/28 19:19:06 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_v3	subtract_vectors(const t_v3 a, const t_v3 b)
{
	t_v3	final_vector;

	final_vector.x = b.x - a.x;
	final_vector.y = b.y - a.y;
	final_vector.z = b.z - a.z;
	return (final_vector);
}

t_v3	add_vectors(const t_v3 a, const t_v3 b)
{
	t_v3	final_vector;

	final_vector.x = a.x + b.x;
	final_vector.y = a.y + b.y;
	final_vector.z = a.z + b.z;
	return (final_vector);
}

double	dot(const t_v3 a, const t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

double	min_double(double a, double b)
{
	if (a <= 0 && b > 0)
		return (b);
	if (b <= 0 && a > 0)
		return (a);
	if (a < b)
		return (a);
	return (b);
}
