/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/07/17 16:40:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_sphere	*set_sphere()
{
	t_sphere	*sphere;
	
	sphere = ft_smart_malloc(sizeof(t_sphere));
	sphere->pos.x = 0;
	sphere->pos.y = 0;
	sphere->pos.z = 30;
	sphere->radius = 3;
	sphere->color = create_trgb(0, 0, 215, 0);
	return (sphere);
}
