/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 23:45:12 by zanybeyonda       #+#    #+#             */
/*   Updated: 2024/08/08 17:21:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ambi_int(t_objects *world)
{
	double			intensity;
	t_light			*light;

	light = return_type(world, A_LIGHT);
	if (light)
		return (math_color_by(light->color, light->intensity, 0));
	return (0);
}

t_light	*set_light(t_v3 pos, double intensity, int color)
{
	t_light	*light;

	light = ft_smart_malloc(sizeof(t_light));
	light->pos = pos;
	light->intensity = intensity;
	light->color = color;
	return (light);
}

int	compute_light_shadow_2(t_light	*light, t_ray *ray,
		int diffuse, t_objects *obj)
{
	t_v3	l;
	double	d;
	t_v3	normal;
	double	dot_n_l;
	int		color;

	color = create_trgb(0, 0, 0, 0);
	if (shadow_ray())
		return (color);
	l = subtract_vectors(ray->origin, light->pos);
	normalize(&l);
	d = vec_len(ray->origin, light->pos);
	normal = normal_at_intersection(obj, ray->origin);
	dot_n_l = dot(normal, l);
	if (dot_n_l < 0)
		dot_n_l = 0;
	color = math_color_by(math_color_by(diffuse, dot_n_l, 0),
			(light->intensity / (d * d)), 0);
	color = math_colors(color, light->color, 2);
	return (color);
}

int	compute_light_shadow(t_objects *world,
		t_objects *object, int diffuse, t_ray *ray)
{
	int	color;

	color = create_trgb(0, 0, 0, 0);
	while (world)
	{
		if (world->type == A_LIGHT)
			color = math_colors(compute_light_shadow_2(world->data,
						ray, diffuse, object), color, 0);
		world = world->next;
	}
	return (color);
}
