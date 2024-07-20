/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:33:43 by user              #+#    #+#             */
/*   Updated: 2024/07/20 17:58:24 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_plane	*set_plane()
{
	t_plane	*plane;

	plane = ft_smart_malloc(sizeof(t_plane));
	plane->pos.x = 0;
	plane->pos.y = 0;
	plane->pos.z = 0;
	plane->normal.x = 0;
	plane->normal.y = 1;
	plane->normal.z = 0;
	plane->color = create_trgb(0, 255, 0, 0);
	return (plane);
}

int	set_plane_color(t_plane *plane)
{
	return (plane->color);
}

double	*hit_plane(t_plane *plane, const t_ray *ray)
{
	double	vd;
	double	v0;
	double	*t;
	double	dee;

	t = ft_smart_malloc(sizeof(double) * 2);
	vd = dot(&plane->normal, &ray->direction);
	if (fabs(vd) < 1e-9)
		return (0);
	dee = -(plane->pos.x + plane->pos.y + plane->pos.z);
	v0 = -(dot(&plane->normal, &ray->origin) + dee);
	t[0] = v0 / vd;
	t[1] = 0;
	if (t[0] <= 0)
	{
		free(t);
		return (NULL);
	}
	return (t);
}

int	plane_normal(t_plane *plane)
{
	return (create_trgb(0, 127.5 * (plane->normal.x + 1),
			127.5 * (plane->normal.y + 1), 127.5 * (plane->normal.z + 1)));
}
