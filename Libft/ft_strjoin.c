/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:20:01 by zvakil            #+#    #+#             */
/*   Updated: 2023/07/30 16:44:38 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		a;
	int		b;
	int		c;

	a = ft_strlen(s1) + ft_strlen(s2);
	b = 0;
	c = 0;
	s3 = (char *)malloc((a + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[c] != '\0')
		s3[b++] = s1[c++];
	c = 0;
	while (s2[c] != '\0')
		s3[b++] = s2[c++];
	s3[b] = '\0';
	return (s3);
}
