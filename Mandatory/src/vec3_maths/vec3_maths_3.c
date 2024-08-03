/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_maths_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:45:35 by zanybeyonda       #+#    #+#             */
/*   Updated: 2024/08/03 12:04:10 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_v3	create_v3(double x, double y, double z)
{
	t_v3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}
