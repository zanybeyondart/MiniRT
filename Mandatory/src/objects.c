/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:20 by user              #+#    #+#             */
/*   Updated: 2024/07/21 23:01:26 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_objects	*load_objects()
{
	t_objects	*obj;
	t_objects	*obj2;

	obj = ft_smart_malloc(sizeof(t_objects));
	obj2 = ft_smart_malloc(sizeof(t_objects));
	obj->data = set_sphere();
	obj->type = SPHERE;
	obj->id = 1;
	obj2->data = set_plane();
	obj2->type = PLANE;
	obj2->next = NULL;
	obj2->id = 2;
	obj->next = obj2;
	get_objects(obj, 1);
	return (obj);
}

t_objects	*get_objects(t_objects *obj, int change)
{
	static t_objects	*final_obj;

	if (change == 1)
		final_obj = obj;
	return (final_obj);
}
