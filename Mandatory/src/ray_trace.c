/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:01:56 by user              #+#    #+#             */
/*   Updated: 2024/08/31 13:28:22 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ray	set_hitpoint(t_objects *obj, double *t, t_ray *ray)
{
	if (obj->type == SPHERE)
		return (sphere_hitray(obj->data, t, ray));
	else if (obj->type == PLANE)
		return (plane_hitray(obj->data, t, ray));
	else if (obj->type == CYLINDER)
		return (cylinder_hitray(obj->data, t, ray));
	return (plane_hitray(obj->data, t, ray));
}

int	bounce_ray(t_ray ray, t_objects *hit, t_objects *main, double *lim_dep)
{
	int			color;
	double		*t;

	t = NULL;
	color = data_color(main, NULL);
	lim_dep[0] = DIFFUSE_RAY_LIMIT;
	if (lim_dep[1] > DIFFUSE_RAY_BOUNCES)
		return (color);
	t = hit_object(hit, &ray, lim_dep);
	if (t)
	{
		color = data_color(hit, t);
		lim_dep[1]++;
		color = ray_trace(get_objects(NULL, 0),
				set_hitpoint(hit, t, &ray), color, lim_dep);
		free(t);
	}
	return (color);
}

int	diffuse(t_ray ray, t_objects *obj, t_objects *w_objs, double *lim_dep)
{
	int			color;
	int			new_color;
	int			samples;

	color = compute_light_shadow(w_objs, obj, data_color(obj, NULL), &ray);
	while (w_objs && color != 0)
	{
		samples = SAMPLES;
		if (obj->id != w_objs->id)
		{
			while (samples > 0)
			{
				new_color = bounce_ray(random_ray (ray.direction, ray.origin),
						w_objs, obj, lim_dep);
				if (new_color != data_color(obj, NULL))
					color = avg_color_2(color, new_color);
				samples--;
			}
		}
		w_objs = w_objs->next;
	}
	return (color);
}

int	set_ray_color(t_ray *ray, double *closest, t_objects *obj, double *lim_dep)
{
	int	color;

	color = 0;
	if (obj->type == SPHERE)
		color = diffuse(sphere_hitray(obj->data, closest, ray),
				obj, get_objects(NULL, 0), lim_dep);
	else if (obj->type == PLANE)
		color = diffuse(plane_hitray(obj->data, closest, ray),
				obj, get_objects(NULL, 0), lim_dep);
	else if (obj->type == CYLINDER)
		color = diffuse(cylinder_hitray(obj->data, closest, ray),
				obj, get_objects(NULL, 0), lim_dep);
	return (color);
}

int	ray_trace(t_objects *obj, t_ray ray, int color, double *lim_dep)
{
	double		*closest;
	double		*new;
	t_objects	*closest_obj;

	closest = NULL;
	new = NULL;
	closest_obj = NULL;
	while (obj)
	{
		new = hit_object(obj, &ray, lim_dep);
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
		color = set_ray_color(&ray, closest, closest_obj, lim_dep);
	return (math_colors(color,
			ambi_int(get_objects(NULL, 0), data_color(closest_obj, NULL)), 0));
	return (math_colors(color,
			0, 0));
}
