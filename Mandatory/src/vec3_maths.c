/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_maths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:05:25 by zvakil            #+#    #+#             */
/*   Updated: 2024/07/14 11:07:30 by zvakil           ###   ########.fr       */
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
