/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 23:45:12 by zanybeyonda       #+#    #+#             */
/*   Updated: 2024/08/25 14:41:31 by zanybeyonda      ###   ########.fr       */
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

int	shadow_ray(t_ray *ray, t_light *light, double d)
{
	t_ray		shadow_ray;
	double		*t;
	t_objects	*world;

	world = get_objects(NULL, 0);
	shadow_ray.origin = ray->origin;
	shadow_ray.direction = subtract_vectors(shadow_ray.origin, light->pos);
	while (world)
	{
		t = NULL;
		t = hit_object(world, &shadow_ray, NULL);
		if (t && t[0] < d)
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

t_v3	random_offset(double radius)
{
	t_v3	offset;
	double	theta_phi[2];
	double	sin_tp[2];
	double	cos_tp[2];

	theta_phi[0] = 2 * M_PI * random_double();
	theta_phi[1] = acos(2 * random_double() - 1);
	sin_tp[0] = sin(theta_phi[0]);
	cos_tp[0] = cos(theta_phi[0]);
	sin_tp[1] = sin(theta_phi[1]);
	cos_tp[1] = cos(theta_phi[1]);
	offset.x = radius * sin_tp[1] * cos_tp[0];
	offset.y = radius * sin_tp[1] * sin_tp[0];
	offset.z = radius * cos_tp[1];
	return (offset);
}

double	compute_light_shadow_3(t_light *light, t_ray *ray, t_v3 normal)
{
	int		i;
	t_v3	offset;
	t_v3	sample_pos;
	t_ray	shadow_ray;
	double	total_light;

	i = 0;
	total_light = 0;
	while (i < SAMPLES + 2)
	{
		offset = random_offset(2);
		sample_pos = add_vectors(light->pos, offset);
		shadow_ray.origin = ray->origin;
		shadow_ray.direction = subtract_vectors(ray->origin, sample_pos);
		normalize(&shadow_ray.direction);
		double sample_d = vec_len(ray->origin, sample_pos);
		double light_intensity = light->intensity / (sample_d * sample_d);
		double sample_dot_n_l = dot(normal, shadow_ray.direction);
		if (sample_dot_n_l < 0)
			sample_dot_n_l = 0;
		total_light += light_intensity * sample_dot_n_l;
		i++;
	}
	return (total_light / SAMPLES);
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
	l = subtract_vectors(ray->origin, light->pos);
	normalize(&l);
	d = vec_len(ray->origin, light->pos);
	//if (shadow_ray(ray, light, d))
	//	return (color);
	normal = normal_at_intersection(obj, ray->origin);
	color = math_color_by(diffuse,
			compute_light_shadow_3(light, ray, normal), 0);
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
		if (world->type == P_LIGHT)
			color = math_colors(compute_light_shadow_2(world->data,
						ray, diffuse, object), color, 0);
		world = world->next;
	}
	return (color);
}
