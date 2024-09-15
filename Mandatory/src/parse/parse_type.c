/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:28:49 by mtashrif          #+#    #+#             */
/*   Updated: 2024/09/15 04:56:04 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	check_comma(char *input)
{
	int	flag;
	int	i;
	int	comma;

	comma = 0;
	i = 0;
	flag = 2;
	while (input[i])
	{
		if (input[i] == ',')
			comma++;
		i++;
	}
	if (comma != flag)
	{
		printf("Error: Incorrect count of commas\n");
		return (1);
	}
	return (0);
}

int	validate_split(char **arr, int expected_count)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (arr[count])
		count++;
	if (count != expected_count)
	{
		printf("Error: Incorrect number of values. Expected %d "\
			"values separated by commas.\n", expected_count);
		return (1);
	}
	while (i < expected_count)
	{
		if (arr[i][0] == '\0')
		{
			printf("Error: Missing value between commas.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	parse_xyz(char *input, double xyz[3])
{
	char	**arr_xyz;
	int		u;

	u = 0;
	if (check_comma(input) == 1)
		return (1);
	arr_xyz = ft_split_2(input, ',', 1);
	if (!arr_xyz || validate_split(arr_xyz, 3))
	{
		free_split(arr_xyz);
		return (1);
	}
	while (arr_xyz[u])
	{
		xyz[u] = ft_atof(arr_xyz[u]);
		u++;
	}
	free_split(arr_xyz);
	return (0);
}

int	parse_normal(char *input, double normal[3])
{
	char	**arr_normal;
	int		u;

	u = 0;
	if (check_comma(input) == 1)
		return (1);
	arr_normal = ft_split_2(input, ',', 1);
	if (!arr_normal || validate_split(arr_normal, 3))
	{
		free_split(arr_normal);
		return (1);
	}
	while (arr_normal[u])
	{
		normal[u] = ft_atof(arr_normal[u]);
		u++;
	}
	free_split(arr_normal);
	return (0);
}

int	parse_rgb(char *input, double rgb[3])
{
	char	**arr_rgb;
	int		u;

	u = 0;
	if (check_comma(input) == 1)
		return (1);
	arr_rgb = ft_split_2(input, ',', 1);
	if (!arr_rgb || validate_split(arr_rgb, 3))
	{
		free_split(arr_rgb);
		return (1);
	}
	while (arr_rgb[u])
	{
		rgb[u] = ft_atof(arr_rgb[u]);
		u++;
	}
	free_split(arr_rgb);
	return (0);
}
