/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:47:36 by zvakil            #+#    #+#             */
/*   Updated: 2023/07/22 13:20:08 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s2 = (const char*)s;
	size_t		a;

	a = 0;
	while (s2[a] != '\0' && a < n)
	{
		if (s2[a] == c)
			return ((void *)s2 + a);
		a++;
	}
	return (NULL);
}
