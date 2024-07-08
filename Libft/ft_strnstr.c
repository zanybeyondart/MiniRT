/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:29:38 by zvakil            #+#    #+#             */
/*   Updated: 2023/07/22 13:35:56 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *s2, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (s2[a] == '\0')
		return ((char *)s);
	if (ft_strlen(s) < ft_strlen(s2))
		return (NULL);
	while (s[a] != '\0' && a < len)
	{
		b = 0;
		while (s[a + b] == s2[b] && a + b < len && s2[b] != '\0')
			b++;
		if (b == len || s2[b] == '\0')
			return ((char *)s + a);
		a++;
	}
	return (NULL);
}
