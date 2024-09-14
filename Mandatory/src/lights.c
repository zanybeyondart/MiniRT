/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 23:45:12 by zanybeyonda       #+#    #+#             */
/*   Updated: 2024/09/15 03:00:33 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ambi_int(t_objects *world, int color)
{
	t_light			*light;

	light = return_type(world, A_LIGHT);
	if (light)
		return (math_color_by(color, light->intensity, 0));
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

int	plane_obstruct(t_cam *cam, t_light *light, t_plane *plane)
{
	t_v3	cam_plane;
	t_v3	plane_light;
	double	dot_cam;
	double	dot_light;

	cam_plane = subtract_vectors(cam->pos, plane->pos);
	plane_light = subtract_vectors(light->pos, plane->pos);
	dot_cam = dot(plane->normal, cam_plane);
	dot_light = dot(plane->normal, plane_light);
	if (dot_cam * dot_light > 0)
		return (0);
	return (1);
}

int	shadow_ray(t_ray *ray, t_light *light, double d, t_objects *obj)
{
	t_ray		shadow_ray;
	double		*t;
	t_objects	*world;

	world = get_objects(NULL, 0);
	shadow_ray.origin = ray->origin;
	shadow_ray.direction = subtract_vectors(shadow_ray.origin, light->pos);
	normalize(&shadow_ray.direction);
	if (obj->type == PLANE
		&& plane_obstruct(get_camera(NULL, 0), light, obj->data))
		return (1);
	while (world)
	{
		t = NULL;
		t = hit_object(world, &shadow_ray, NULL);
		if (t && t[0] < d && t[0] >= 1e-9)
		{
			free(t);
			return (1);
		}
		if (t)
			free(t);
		world = world->next;
	}
	return (0);
}

double	random_double(void)
{
	return ((double)rand() / (double)RAND_MAX);
}
