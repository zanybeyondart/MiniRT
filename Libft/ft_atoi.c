/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:15:54 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/13 16:48:27 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*skip_whitespace(char *str)
{
	while (*str && isspace((unsigned char)*str))
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	neg;

	b = 0;
	a = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			neg = 1;
		a++;
	}
	while (ft_isdigit(str[a]))
	{
		b = b * 10 + (str[a] - 48);
		a++;
	}
	if (neg == 1)
		return (b * -1);
	else
		return (b);
}
