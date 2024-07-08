/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:20:18 by zvakil            #+#    #+#             */
/*   Updated: 2023/07/30 16:39:46 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	a;
	int				b;
	char			*temp;

	if (start > ft_strlen(s))
	{
		temp = (char *)malloc(sizeof(char));
		if (!s)
			return (NULL);
		temp[0] = '\0';
		return (temp);
	}
	a = start;
	b = 0;
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s[a] != '\0' && b < (int)len)
	{
		temp[b] = s[a];
		a++;
		b++;
	}
	temp[b] = '\0';
	return (temp);
}
