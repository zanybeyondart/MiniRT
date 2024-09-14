/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_maths_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 01:45:35 by zanybeyonda       #+#    #+#             */
/*   Updated: 2024/09/15 03:01:53 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_v3	create_v3(double x, double y, double z)
{
	t_v3	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
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
	while (i < SAMPLES + 1)
	{
		offset = random_offset(1);
		sample_pos = add_vectors(light->pos, offset);
		shadow_ray.origin = ray->origin;
		shadow_ray.direction = subtract_vectors(ray->origin, sample_pos);
		normalize(&shadow_ray.direction);
		if (fabs(dot(normal, shadow_ray.direction)) < 1e-9)
			continue ;
		total_light += (light->intensity
				/ pow(vec_len(ray->origin, sample_pos), 2))
			* dot(normal, shadow_ray.direction);
		i++;
	}
	return (total_light / (SAMPLES + 1));
}

int	compute_light_shadow_2(t_light	*light, t_ray *ray,
		int diffuse, t_objects *obj)
{
	t_v3	l;
	double	d;
	t_v3	normal;
	int		color;

	color = create_trgb(0, 0, 0, 0);
	l = subtract_vectors(ray->origin, light->pos);
	normalize(&l);
	d = vec_len(ray->origin, light->pos);
	if (shadow_ray(ray, light, d, obj))
		return (color);
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
