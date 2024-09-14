/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:30:24 by mtashrif          #+#    #+#             */
/*   Updated: 2024/09/15 02:06:37 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	parse_fractional_part(char **str)
{
	double	fractional_part;
	double	divisor;

	fractional_part = 0.0;
	divisor = 10.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			fractional_part += (**str - '0') / divisor;
			divisor *= 10.0;
			(*str)++;
		}
	}
	return (fractional_part);
}

double	parse_exponential_part(char **str)
{
	double	exponential_part;
	int		exp_sign;
	int		exponent;

	exponential_part = 1.0;
	if (**str == 'e' || **str == 'E')
	{
		(*str)++;
		exp_sign = parse_sign(str);
		exponent = parse_integer_part(str);
		while (exponent-- > 0)
		{
			if (exp_sign == 1)
				exponential_part *= 10.0;
			else
				exponential_part *= 0.1;
		}
	}
	return (exponential_part);
}

double	ft_atof(const char *str)
{
	char	*s;
	double	result;
	int		sign;

	s = (char *)str;
	s = skip_whitespace(s);
	sign = parse_sign(&s);
	result = parse_integer_part(&s);
	result += parse_fractional_part(&s);
	result *= parse_exponential_part(&s);
	return (result * sign);
}
