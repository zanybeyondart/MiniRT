/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:29:05 by mtashrif          #+#    #+#             */
/*   Updated: 2024/09/15 02:31:33 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_split_result(char **split_result)
{
	int	h;

	h = 0;
	printf("\n//This is the string divide\n");
	while (split_result[h])
	{
		printf("From Mini Function => Word[%d]: %s\n", h, split_result[h]);
		h++;
	}
}

void	print_array_char(char **arr)
{
	int	k;

	k = 0;
	printf("\n//This is the colour divide\n");
	while (arr[k])
	{
		printf("From Mini Function => This is Char array[%d]: %s\n", k, arr[k]);
		k++;
	}
	printf("\n");
}

void	print_array_float(double *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		printf("From Mini Function => This is " \
		"Float Array %d = %f \n", i + 1, rgb[i]);
		i++;
	}
}

int	parse_split(char **s, char letter)
{
	if (letter == 'A')
	{
		if (!s[0] || !s[1] || !s[2] || s[3])
		{
			printf("Error: Check number of Parameters for type %c\n", letter);
			return (1);
		}
	}
	if (letter == 'C' || letter == 'L' || letter == 's' || letter == 'p')
	{
		if (!s[0] || !s[1] || !s[2] || !s[3] || s[4])
		{
			printf("Error: Check number of Parameters for type %c\n", letter);
			return (1);
		}
	}
	if (letter == 'c')
	{
		if (!s[0] || !s[1] || !s[2] || !s[3] || !s[4] || !s[5] || s[6])
		{
			printf("Error: Check number of Parameters for type %c\n", letter);
			return (1);
		}
	}
	return (0);
}
