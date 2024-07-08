/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:19:20 by zvakil            #+#    #+#             */
/*   Updated: 2023/08/06 12:50:46 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	checks(int b)
{
	int	a;

	a = 0;
	if (b < 0)
		a++;
	if (b == 0)
		return (1);
	while (b != 0)
	{
		b = b / 10;
		a++;
	}
	return (a);
}

char	assign_char(int new, int n)
{
	char	f;

	if (n < 0)
		f = ((new % 10) * -1) + '0';
	else
		f = new % 10 + '0';
	return (f);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		new;

	new = n;
	s = (char *) malloc (sizeof(char) * (checks(n) + 1));
	if (!s)
		return (NULL);
	len = (checks(n));
	s[len--] = '\0';
	while (len >= 0)
	{
		if (n < 0 && len == 0)
		{
			s[0] = '-';
			break ;
		}
		s[len--] = assign_char(new, n);
		new /= 10;
	}
	return (s);
}
