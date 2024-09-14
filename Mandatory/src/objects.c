/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:20 by user              #+#    #+#             */
/*   Updated: 2024/09/15 03:22:43 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_objects	*add_to_list(t_objects *main, void *data, t_objs type, int id)
{
	t_objects	*new;
	t_objects	*current;

	new = ft_smart_malloc(sizeof(t_objects));
	new->data = data;
	new->id = id;
	new->type = type;
	new->next = NULL;
	if (main == NULL)
		return (get_objects(new, 1));
	current = main;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (main);
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
