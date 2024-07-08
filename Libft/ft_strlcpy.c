/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:33:46 by zvakil            #+#    #+#             */
/*   Updated: 2023/07/22 13:33:48 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (size > 0)
	{
		while (a < size - 1)
		{
			if (src[a] != '\0')
				dst[a] = src[a];
			else
				break ;
			a++;
		}
		dst[a] = '\0';
	}
	return (ft_strlen(src));
}
