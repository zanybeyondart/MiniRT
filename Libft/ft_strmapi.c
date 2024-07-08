/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:20:07 by zvakil            #+#    #+#             */
/*   Updated: 2023/08/05 19:01:48 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*str;

	a = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[a] != '\0')
	{
		str[a] = f (a, s[a]);
		a++;
	}
	str[a] = '\0';
	return (str);
}
