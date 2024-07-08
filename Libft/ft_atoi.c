/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:15:54 by zvakil            #+#    #+#             */
/*   Updated: 2023/08/06 02:00:19 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
