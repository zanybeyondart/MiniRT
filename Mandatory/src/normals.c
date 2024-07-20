/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:47:48 by zvakil            #+#    #+#             */
/*   Updated: 2024/07/20 17:57:49 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	normalize(t_v3 *vector)
{
	double	len;

	len = sqrt(pow(vector->x, 2) + pow(vector->y, 2) + pow(vector->z, 2));
	vector->x = vector->x / len;
	vector->y = vector->y / len;
	vector->z = vector->z / len;
}
