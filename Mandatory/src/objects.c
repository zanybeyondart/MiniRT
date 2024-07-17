/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:20 by user              #+#    #+#             */
/*   Updated: 2024/07/17 17:31:54 by user             ###   ########.fr       */
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
	obj2->data = set_plane();
	obj2->type = PLANE;
	obj->next = obj2;
	return (obj);
}
