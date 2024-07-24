/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:01:56 by user              #+#    #+#             */
/*   Updated: 2024/07/24 17:33:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ray	set_hitpoint(t_objects *obj, double *t, t_ray *ray)
{
	if (obj->type == SPHERE)
		return (sphere_hitray(obj->data, t, ray));
	else if (obj->type == PLANE)
		return (plane_hitray(obj->data, t, ray));
}

int	bounce_ray(t_ray ray, t_objects *hit, int depth, t_objects *main)
{
	int			color;
	double		*t;

	t = NULL;
	color = data_color(main);
	t = hit_object(hit, &ray);
	if (t)
	{
		color = data_color(hit);
		free(t);
	}
	return (color);
}

int	diffuse(t_ray ray, t_objects *obj, t_objects *w_objs, int samples)
{
	int	color;

	color = data_color(obj);
	while (w_objs)
	{
		//samples = 10;
		if (obj->id != w_objs->id)
		{
			while (samples > 0)
			{
				color = avg_color_2(color, bounce_ray(random_ray
							(ray.direction, ray.origin), w_objs, 0, obj));
				samples--;
			}
		}
		w_objs = w_objs->next;
	}
	return (color);
}

double	*hit_object(t_objects *obj, t_ray *ray)
{
	double	*new;

	new = NULL;
	if (obj->type == SPHERE)
		new = hit_sphere(obj->data, ray);
	else if (obj->type == PLANE)
		new = hit_plane(obj->data, ray);
	return (new);
}

int	set_ray_color(t_ray *ray, double *closest, t_objects *obj, int color)
{
	if (obj->type == SPHERE)
		color = diffuse(sphere_hitray(obj->data, closest, ray),
				obj, get_objects(NULL, 0), 10);
	else if (obj->type == PLANE)
		color = diffuse(plane_hitray(obj->data, closest, ray),
				obj, get_objects(NULL, 0), 10);
	return (color);
}

int	ray_trace(t_objects *obj, t_ray ray)
{
	int			color;
	double		*closest;
	double		*new;
	t_objects	*closest_obj;

	closest = NULL;
	new = NULL;
	color = create_trgb(0, 160, 32, 240);
	while (obj)
	{
		new = hit_object(obj, &ray);
		if ((new && closest == NULL) || (new && closest && new[0] < closest[0]))
		{
			if (closest)
				free(closest);
			closest = new;
			closest_obj = obj;
		}
		else if (new)
			free(new);
		obj = obj->next;
	}
	if (closest)
	{
		color = set_ray_color(&ray, closest, closest_obj, color);
		free(closest);
	}
	return (color);
}
