/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:20 by user              #+#    #+#             */
/*   Updated: 2024/09/14 15:12:18 by zvakil           ###   ########.fr       */
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

	obj = NULL;
	//obj = add_to_list(obj, set_sphere(-10, 0, 0, create_trgb(0, 255, 0, 0)), SPHERE, 1);
	obj = add_to_list(obj, set_sphere(0, 0, 10, create_trgb(0, 120, 0, 0)), SPHERE, 2);
	//obj = add_to_list(obj, set_sphere(3, 0, 10, create_trgb(0, 0, 120, 0)), SPHERE, 3);
	//obj = add_to_list(obj, set_sphere(0, 6, 10, create_trgb(0, 0, 225, 0)), SPHERE, 7);
	obj = add_to_list(obj, set_plane(), PLANE, 4);
	obj = add_to_list(obj, set_light(create_v3(0, 0, 0), 0.5, create_trgb(0, 255, 255, 255)), A_LIGHT, 5);
	//obj = add_to_list(obj, set_cylinder(0, 0, 5, create_trgb(0, 225, 0, 225)), CYLINDER, 6);
	obj = add_to_list(obj, set_light(create_v3(5, 6, 5), 1, create_trgb(0, 255, 255, 255)), P_LIGHT, 6);
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

t_vars	*get_vars(t_vars *vars, int change)
{
	static t_vars	*final_vars;

	if (change == 1)
		final_vars = vars;
	return (final_vars);
}

t_v3	normal_at_intersection(t_objects *obj, t_v3 point)
{
	if (obj->type == SPHERE)
		return (sphere_normal_at_point(obj->data, point));
	else if (obj->type == PLANE)
		return (plane_normal(obj->data));
	else if (obj->type == CYLINDER)
		return (cylinder_surface_normal(obj->data, point));
	return (create_v3(0, 0, 0));
}
