/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_maths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:05:25 by zvakil            #+#    #+#             */
/*   Updated: 2024/07/19 17:23:40 by user             ###   ########.fr       */
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

void	normalize(t_v3 *vector)
{
	double	len;

	len = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
	vector->x = vector->x / len;
	vector->y = vector->y / len;
	vector->z = vector->z / len;
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
