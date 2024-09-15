/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:44:03 by zvakil            #+#    #+#             */
/*   Updated: 2024/09/15 03:57:34 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_whitespace(char c, int bool_value)
{
	return (c == ' ' || c == '\t' || c == '\n' \
	|| (bool_value == 1 && c == ','));
}

int	countword(const char *s, int bool_value)
{
	int	a;
	int	d;

	d = 0;
	a = 0;
	while (s[a] != '\0')
	{
		while (is_whitespace((s[a]), bool_value))
			a++;
		if (s[a] != '\0')
		{
			d++;
			while (!is_whitespace((s[a]), bool_value) && s[a] != '\0')
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

char	**ft_split_2(const char *s, char c, int bool_value)
{
	int		v[2];
	int		start;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (countword(s, bool_value) + 1));
	if (!result)
		return (NULL);
	v[0] = 0;
	v[1] = 0;
	while (s[v[0]] != '\0' && v[1] < countword(s, bool_value))
	{
		while (is_whitespace((s[v[0]]), bool_value))
			v[0]++;
		start = v[0];
		while (!is_whitespace((s[v[0]]), bool_value) && s[v[0]] != '\0')
			v[0]++;
		result[v[1]++] = wordassign(s + start, v[0] - start);
	}
	result[v[1]] = NULL;
	return (result);
}
