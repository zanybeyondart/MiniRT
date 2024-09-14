/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:08:02 by mtashrif          #+#    #+#             */
/*   Updated: 2024/09/15 02:06:34 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_whitespace(char *str)
{
	while (*str && ft_isspace((unsigned char)*str))
		str++;
	return (str);
}

int	parse_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
	{
		(*str)++;
	}
	return (sign);
}

double	parse_integer_part(char **str)
{
	double	integer_part;

	integer_part = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		integer_part = integer_part * 10.0 + (**str - '0');
		(*str)++;
	}
	return (integer_part);
}
