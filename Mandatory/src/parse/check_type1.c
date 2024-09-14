/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:01:41 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/15 03:23:42 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_ambient(char *str)
{
	char	**split;
	double	ambient_lighting;
	double	rgb[3];

	ambient_lighting = 0;
	split = ft_split_2(str, ' ', 0);
	if (parse_split(split, 'A') == 1)
		return (ft_free(&split, 'a'), 1);
	if (split[1])
		ambient_lighting = ft_atof(split[1]);
	if (check_lighting_range(ambient_lighting) != 0)
		return (ft_free(&split, 'a'), 1);
	if (split[2] && parse_rgb(split[2], rgb))
		return (ft_free(&split, 'a'), 1);
	if (check_rgb_range(rgb) != 0)
		return (ft_free(&split, 'a'), 1);
	add_to_list(get_objects(NULL, 0), set_light(create_v3(0, 0, 0),
			ambient_lighting, create_trgb(0, rgb[0], rgb[1], rgb[2])),
		A_LIGHT, 2);
	return (ft_free(&split, 'a'), 0);
}

int	check_light(char *str)
{
	char	**split_result;
	double	light_brightness;
	double	rgb[3];
	double	xyz[3];

	light_brightness = 0;
	split_result = ft_split_2(str, ' ', 0);
	if (parse_split(split_result, 'L') == 1)
		return (ft_free(&split_result, 'a'), 1);
	if (split_result[1] && parse_xyz(split_result[1], xyz))
		return (ft_free(&split_result, 'a'), 1);
	if (split_result[2])
		light_brightness = ft_atof(split_result[2]);
	if (check_lighting_range(light_brightness) != 0)
		return (ft_free(&split_result, 'a'), 1);
	if (split_result[3] && parse_rgb(split_result[3], rgb))
		return (1);
	if (check_rgb_range(rgb) != 0)
		return (ft_free(&split_result, 'a'), 1);
	add_to_list(get_objects(NULL, 0),
		set_light(create_v3(xyz[0], xyz[1], xyz[2]),
			1, create_trgb(0, rgb[0], rgb[1], rgb[2])), P_LIGHT, 4);
	return (ft_free(&split_result, 'a'), 0);
}

int	check_camera(char *str)
{
	char		**split;
	long double	fov;
	double		normal[3];
	double		xyz[3];
	t_cam		*cam;

	fov = 0;
	split = ft_split_2(str, ' ', 0);
	if (parse_split(split, 'C') == 1)
		return (ft_free(&split, 'a'), 1);
	if (split[1] && parse_xyz(split[1], xyz))
		return (ft_free(&split, 'a'), 1);
	if (split[2] && parse_normal(split[2], normal))
		return (ft_free(&split, 'a'), 1);
	if (chk_n_range(normal) != 0)
		return (ft_free(&split, 'a'), 1);
	if (split[3])
		fov = ft_atof(split[3]);
	if (check_fov_range(fov) != 0)
		return (ft_free(&split, 'a'), 1);
	cam = set_cam(xyz, normal, fov);
	get_camera(cam, 1);
	return (ft_free(&split, 'a'), 0);
}
