/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:20 by user              #+#    #+#             */
/*   Updated: 2024/07/24 17:01:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_objects	*load_objects()
{
	t_objects	*obj;
	t_objects	*obj2;
	t_objects	*obj3;

	obj = ft_smart_malloc(sizeof(t_objects));
	obj2 = ft_smart_malloc(sizeof(t_objects));
	obj3 = ft_smart_malloc(sizeof(t_objects));
	obj->data = set_sphere(-2, 0, 4, create_trgb(0, 0, 0, 255));
	obj->type = SPHERE;
	obj->id = 1;
	obj2->data = set_plane();
	obj2->type = PLANE;
	obj2->id = 2;
	obj->next = obj2;
	//obj2->next = NULL;
	obj3->data = set_sphere(2, 0, 4, create_trgb(0, 255, 0, 0));
	obj3->type = SPHERE;
	obj3->id = 3;
	obj3->next = NULL;
	obj2->next = obj3;
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
