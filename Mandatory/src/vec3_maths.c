/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_maths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:05:25 by zvakil            #+#    #+#             */
/*   Updated: 2024/07/22 14:00:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_v3	subtract_vectors(const t_v3 *A, const t_v3 *B)
{
	t_v3	final_vector;

	final_vector.x = B->x - A->x;
	final_vector.y = B->y - A->y;
	final_vector.z = B->z - A->z;
	return (final_vector);
}

t_v3	add_vectors(const t_v3 *A, const t_v3 *B)
{
	t_v3	final_vector;

	final_vector.x = A->x + B->x;
	final_vector.y = A->y + B->y;
	final_vector.z = A->z + B->z;
	return (final_vector);
}

double	dot(const t_v3 *A, const t_v3 *B)
{
	return (A->x * B->x + A->y * B->y + A->z * B->z);
}

int	cam_normal(t_vars *vars, char a)
{
	if (a == 'x')
	{
		if (vars->camera->normal.x >= 0)
			return (1);
		else
			return (-1);
	}
	else if (a == 'y')
	{
		if (vars->camera->normal.y >= 0)
			return (1);
		else
			return (-1);
	}
	else
	{
		if (vars->camera->normal.z >= 0)
			return (1);
		else
			return (-1);
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
