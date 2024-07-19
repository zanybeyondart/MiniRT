/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:33:43 by user              #+#    #+#             */
/*   Updated: 2024/07/18 15:49:51 by user             ###   ########.fr       */
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
	plane->normal.y = -1;
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
    double	Vd;
	double	V0;
	double	*t;
	double	dee;

	t = ft_smart_malloc(sizeof(double) * 2);
    Vd = dot(&plane->normal, &ray->direction);
    if (fabs(Vd) < 1e-9)
        return 0;
	dee = -(plane->pos.x + plane->pos.y + plane->pos.z);
    V0 = -(dot(&plane->normal, &ray->origin) + dee);
    t[0] = V0 / Vd;
	t[1] = 0;
    if (t[0] <= 0)
	{
		free(t);
        return (NULL);
	}
   return (t);
}
