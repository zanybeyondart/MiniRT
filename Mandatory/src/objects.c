/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:20 by user              #+#    #+#             */
/*   Updated: 2024/07/28 22:09:17 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_objects	*add_to_list(t_objects *main, void *data, t_objs type, int id)
{
	t_objects	*new;
	t_objects	*main_bk;

	main_bk = main;
	new = ft_smart_malloc(sizeof(t_objects));
	new->data = data;
	new->id = id;
	new->type = type;
	new->next = NULL;
	if (main == NULL)
	{
		main = new;
		return (main);
	}
	while (main->next)
		main = main->next;
	main->next = new;
	return (main_bk);
}

t_objects	*load_objects()
{
	t_objects	*obj;
	t_objects	*obj2;
	t_objects	*obj3;
	t_objects	*obj4;

	obj = NULL;
	obj = add_to_list(obj, set_sphere(-2, 0, -4, create_trgb(0, 0, 0, 255)), SPHERE, 1);
	obj = add_to_list(obj, set_sphere(2, 0, -4, create_trgb(0, 0, 225, 0)), SPHERE, 2);
	obj = add_to_list(obj, set_sphere(0, 2, -4, create_trgb(0, 225, 0, 0)), SPHERE, 3);
	obj = add_to_list(obj, set_plane(), PLANE, 4);
	obj = add_to_list(obj, set_ambient_light(), AMBI_LIGHT, 5);
	obj = add_to_list(obj, set_cylinder(0, 0, 0, create_trgb(0, 225, 0, 225)), CYLINDER, 6);
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
