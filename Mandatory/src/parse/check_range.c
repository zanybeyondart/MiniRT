/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:28:51 by mtashrif          #+#    #+#             */
/*   Updated: 2024/09/15 02:30:44 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_rgb_range(double rgb[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			printf("Error: RGB value out of bounds. "\
			"RGB values should be between 0 and 255.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	chk_n_range(double normal[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (normal[i] < -1 || normal[i] > 1)
		{
			printf("Error: Normal value out of bounds. "\
			"3D Normal values should be between -1 and 1.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_lighting_range(double lighting)
{
	if (lighting < 0.0 || lighting > 1.0)
	{
		printf("Error: Lighting value out of bounds. "\
		"It should be between 0.0 and 1.0.\n");
		return (1);
	}
	return (0);
}

int	check_fov_range(double fov)
{
	if (fov < 0 || fov > 180)
	{
		printf("Error: FOV fov value out of bounds. "\
		"It should be between 0 and 180.\n");
		return (1);
	}
	return (0);
}
