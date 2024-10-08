/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:45:38 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/15 03:53:10 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_sphere(char *str)
{
	char	**split_result;
	double	diameter;
	double	rgb[3];
	double	xyz[3];

	diameter = 0;
	split_result = ft_split_2(str, ' ', 0);
	if (parse_split(split_result, 's') == 1)
		return (ft_free(&split_result, 'a'), 1);
	if (split_result[1] && parse_xyz(split_result[1], xyz))
		return (ft_free(&split_result, 'a'), 1);
	if (split_result[2])
		diameter = ft_atof(split_result[2]);
	if (diameter <= 0)
	{
		printf("Diameter value cannot be negative\n");
		return (ft_free(&split_result, 'a'), 1);
	}
	if (split_result[3] && parse_rgb(split_result[3], rgb))
		return (ft_free(&split_result, 'a'), 1);
	if (check_rgb_range(rgb) != 0)
		return (ft_free(&split_result, 'a'), 1);
	add_to_list(get_objects(NULL, 0), set_sphere(xyz, diameter / 2, \
			create_trgb(0, rgb[0], rgb[1], rgb[2])), SPHERE, 1);
	return (ft_free(&split_result, 'a'), 0);
}

int	check_plane(char *str)
{
	char	**split_result;
	double	xyz[3];
	double	normal[3];
	double	rgb[3];

	split_result = ft_split_2(str, ' ', 0);
	if (parse_split(split_result, 'p') == 1)
		return (ft_free(&split_result, 'a'), 1);
	if (split_result[1] && parse_xyz(split_result[1], xyz))
		return (ft_free(&split_result, 'a'), 1);
	if (split_result[2] && parse_normal(split_result[2], normal))
		return (ft_free(&split_result, 'a'), 1);
	if (chk_n_range(normal) != 0)
		return (ft_free(&split_result, 'a'), 1);
	if (split_result[3] && parse_rgb(split_result[3], rgb))
		return (ft_free(&split_result, 'a'), 1);
	if (check_rgb_range(rgb) != 0)
		return (ft_free(&split_result, 'a'), 1);
	add_to_list(get_objects(NULL, 0),
		set_plane(xyz, normal, rgb), PLANE, 3);
	return (ft_free(&split_result, 'a'), 0);
}

int	cr_cy(double num, char type)
{
	if (num < 0)
	{
		if (type == 'd')
			printf("Error: Cylinder Diameter cannot be less than 0\n");
		if (type == 'h')
			printf("Error: Cylinder Height cannot be less than 0\n");
		return (1);
	}
	return (0);
}

int	check_cylinder(char *str)
{
	char	**sp;
	double	a[3][3];
	double	cy_dh[2];

	sp = ft_split_2(str, ' ', 0);
	if (parse_split(sp, 'c') == 1)
		return (ft_free(&sp, 'a'), 1);
	if (sp[1] && parse_xyz(sp[1], a[0]))
		return (ft_free(&sp, 'a'), 1);
	if (sp[2] && parse_normal(sp[2], a[1]) && chk_n_range(a[1]) != 0)
		return (ft_free(&sp, 'a'), 1);
	if (sp[3])
		cy_dh[0] = ft_atof(sp[3]);
	if (sp[4])
		cy_dh[1] = ft_atof(sp[4]);
	if (cr_cy(cy_dh[0], 'd') == 1 || cr_cy(cy_dh[1], 'h') == 1)
		return (ft_free(&sp, 'a'), 1);
	if (sp[5] && parse_rgb(sp[5], a[2]) \
		&& check_rgb_range(a[2]) != 0)
		return (ft_free(&sp, 'a'), 1);
	add_to_list(get_objects(NULL, 0), \
	set_cylinder(create_v3(a[0][0], a[0][1], a[0][2]), \
	create_v3(a[1][0], a[1][1], a[1][2]), \
	create_trgb(0, a[2][0], a[2][1], a[2][2]), cy_dh), CYLINDER, 3);
	return (ft_free(&sp, 'a'), 0);
}
