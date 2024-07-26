/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:36:34 by user              #+#    #+#             */
/*   Updated: 2024/07/22 17:47:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

uint32_t	seed(uint32_t new, int set)
{
	static uint32_t	seed;

	if (set)
		seed = new;
	return (seed);
}

uint32_t	rand_custom(void)
{
	uint32_t	new_seed;

	new_seed = 0;
	new_seed = seed(new_seed, 0);
	new_seed = (SEED_A * new_seed + SEED_C) % SEED_M;
	seed(new_seed, 1);
	return (new_seed);
}

double	random_double_custom(void)
{
	return (rand_custom() / (double)SEED_M);
}

t_v3	random_in_unit_sphere(void)
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
