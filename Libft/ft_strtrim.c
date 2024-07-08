/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:53:43 by zvakil            #+#    #+#             */
/*   Updated: 2023/07/30 16:48:43 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	a;
	size_t	b;

	str = 0;
	if (s1 && set)
	{
		a = 0;
		b = ft_strlen(s1);
		while (s1[a] && ft_strchr(set, s1[a]))
			a++;
		while (s1[b - 1] && ft_strchr(set, s1[b - 1]) && b > a)
			b--;
		str = (char *)malloc(sizeof(char) * (b - a + 1));
		if (str)
			ft_strlcpy(str, &s1[a], b - a + 1);
	}
	return (str);
}
