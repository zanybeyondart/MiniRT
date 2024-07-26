/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:20 by user              #+#    #+#             */
/*   Updated: 2024/07/26 19:55:01 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_objects	*load_objects()
{
	t_objects	*obj;
	t_objects	*obj2;
	t_objects	*obj3;
	t_objects	*obj4;

	obj = ft_smart_malloc(sizeof(t_objects));
	obj2 = ft_smart_malloc(sizeof(t_objects));
	obj3 = ft_smart_malloc(sizeof(t_objects));
	obj4 = ft_smart_malloc(sizeof(t_objects));
	obj->data = set_sphere(-2, 0, 4, create_trgb(0, 0, 0, 255));
	obj->type = SPHERE;
	obj->id = 1;
	obj->next = NULL;
	obj2->data = set_sphere(2, 0, 4, create_trgb(0, 0, 255, 0));
	obj2->type = SPHERE;
	obj2->id = 2;
	obj2->next = NULL;
	obj->next = obj2;
	obj3->data = set_sphere(0, 2, 4, create_trgb(0, 255, 0, 0));
	obj3->type = SPHERE;
	obj3->id = 3;
	obj3->next = NULL;
	obj2->next = obj3;
	obj4->data = set_plane();
	obj4->type = PLANE;
	obj4->id = 4;
	obj4->next = NULL;
	obj3->next = obj4;
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
