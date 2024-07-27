/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 23:45:12 by zanybeyonda       #+#    #+#             */
/*   Updated: 2024/07/27 00:34:12 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ambi_int(t_objects *world)
{
	double			intensity;
	t_ambient_light	*light;

	light = return_type(world, AMBI_LIGHT);
	if (light)
		return (math_color_by(light->color, light->intensity, 0));
	return (0);
}

t_ambient_light	*set_ambient_light()
{
	t_ambient_light	*light;

	light = ft_smart_malloc(sizeof(t_ambient_light));
	light->intensity = 0.1;
	light->color = create_trgb(0, 150, 150, 150);
	return (light);
}
