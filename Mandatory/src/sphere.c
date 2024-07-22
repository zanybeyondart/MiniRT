/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/07/22 10:54:28 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_sphere	*set_sphere()
{
	t_sphere	*sphere;

	sphere = ft_smart_malloc(sizeof(t_sphere));
	sphere->pos.x = 0;
	sphere->pos.y = 5;
	sphere->pos.z = -4;
	sphere->radius = 5;
	sphere->color = create_trgb(0, 244, 0, 0);
	return (sphere);
}

int	set_sphere_color(t_sphere *sphere)
{
	return (sphere->color);
}

int	ray_color(t_ray	ray, t_objects *h_object, int depth, t_objects *m_object)
{
	double		*t_dyn;
	double		t[2];
	t_plane		*plane;
	t_sphere	*sphere;
	int			color;

	t_dyn = NULL;
	if (h_object->type == PLANE)
	{
		plane = h_object->data;
		sphere = m_object->data;
		color = sphere->color;
		t_dyn = hit_plane(plane, &ray);
		if (t_dyn)
			color = plane->color;
	}
	else
	{
			plane = m_object->data;
		sphere = h_object->data;
		color = plane->color;
		t_dyn = hit_sphere(sphere, &ray);
		if (t_dyn)
			color = sphere->color;
	}
	if (t_dyn == NULL)
		return (color);
	// ray_color(, h_object, depth + 1, m_object);
	// t[0] = t_dyn[0];
	// t[1] = t_dyn[1];
	// free(t_dyn);
	return (color);
}

uint32_t	seed(uint32_t new, int set)
{
	static uint32_t seed;

	if (set)
	seed = new;
	return (seed);
}

uint32_t	rand_custom()
{
	uint32_t	new_seed;

	new_seed = seed(new_seed, 0);
	new_seed = (AB * new_seed + C) % M;
	seed(new_seed, 1);
	return (new_seed);
}

double	random_double_custom()
{
	return (rand_custom() / (double)M);
}

t_v3	random_in_unit_sphere()
{
	t_v3	p;

	while (1)
	{
		p = (t_v3){random_double_custom() * 2.0 - 1.0,
			random_double_custom() * 2.0 - 1.0,
			random_double_custom() * 2.0 - 1.0};
		if (dot(&p, &p) < 1.0)
			break ;
	}
	normalize(&p);
	return (p);
}

t_ray	random_ray(t_v3 normal, t_v3 origin)
{
	t_v3	random_dir;
	t_ray	ray;

	random_dir = random_in_unit_sphere();
	if (dot(&random_dir, &normal) < 0.0)
		random_dir = (t_v3){-random_dir.x, -random_dir.y, -random_dir.z};
	ray.direction = random_dir;
	ray.origin = origin;
	return (ray);
}

int	diffuse(t_ray *ray, t_objects *obj, t_objects *w_objs, int samples)
{
	t_sphere	*sphere;
	t_plane		*plane;
	int			color;

	if (obj->type == SPHERE)
	{
	sphere = obj->data;
	color = sphere->color;
	}
	else
	{
		plane = obj->data;
		color = plane->color;
	}
	while (w_objs)
	{
		if (obj->id != w_objs->id)
		{
			if (w_objs->type == PLANE)
			{
				while (samples > 0)
				{
					color = avg_color_2(color, ray_color(random_ray(ray->direction, ray->origin), w_objs, 0, obj));
					samples--;
				}
			}
			else
			{
				while (samples > 0)
				{
					color = avg_color_2(color, ray_color(random_ray(ray->direction, ray->origin), w_objs, 0, obj));
					samples--;
				}
			}
		}
		w_objs = w_objs->next;
	}
	return (color);
}

int	sphere_normal(t_ray *ray, double *t, t_objects *obj, t_objects *w_objs)
{
	t_v3		n;
	t_v3		rayt;
	t_ray		inter;
	t_sphere	*sphere;

	sphere = obj->data;
	rayt.x = ray->origin.x + ray->direction.x * t[0];
	rayt.y = ray->origin.y + ray->direction.y * t[0];
	rayt.z = ray->origin.z + ray->direction.z * t[0];
	inter.origin = rayt;
	n.x = (rayt.x - sphere->pos.x) / sphere->radius;
	n.y = (rayt.y - sphere->pos.y) / sphere->radius;
	n.z = (rayt.z - sphere->pos.z) / sphere->radius;
	normalize(&n);
	inter.direction = n;
	return (diffuse(&inter, obj, w_objs, 100));
}

double	*hit_sphere(t_sphere *sphere, const t_ray *ray)
{
	t_v3	l;
	double	tca;
	double	thc;
	double	d2;
	double	*t;

	l = subtract_vectors(&ray->origin, &sphere->pos);
	tca = dot(&l, &ray->direction);
	if (tca < 0)
		return (NULL);
	d2 = dot(&l, &l) - tca * tca;
	if (d2 > sphere->radius * sphere->radius)
		return (NULL);
	thc = sqrtf(sphere->radius * sphere->radius - d2);
	t = ft_smart_malloc(sizeof(double) * 2);
	t[0] = tca - thc;
	t[1] = tca + thc;
	return (t);
}
