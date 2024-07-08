/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:44:03 by zvakil            #+#    #+#             */
/*   Updated: 2023/07/30 17:56:30 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countword(const char *s, char c)
{
	int	a;
	int	d;

	d = 0;
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] == c)
			a++;
		else
		{
			d++;
			while (s[a] != c && s[a] != '\0')
				a++;
		}
	}
	return (d);
}

char	*wordassign(const char *s, int len)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s, len + 1);
	return (s2);
}

char	**ft_split(const char *s, char c)
{
	int		v[2];
	int		start;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * ((countword (s, c)) + 1));
	if (!result)
		return (NULL);
	v[0] = 0;
	v[1] = 0;
	while (s[v[0]] != '\0' && v[1] < (countword (s, c)))
	{
		if (s[v[0]] == c)
			v[0]++;
		else
		{
			start = v[0];
			while (s[v[0]] != c && s[v[0]] != '\0')
				v[0]++;
			result[v[1]++] = wordassign ((char *) s + start, v[0] - start);
		}
	}
	result[v[1]] = NULL;
	return (result);
}
