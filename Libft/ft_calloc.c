/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:32:27 by zvakil            #+#    #+#             */
/*   Updated: 2023/07/22 13:39:10 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	a;
	char	*ptr;

	a = 0;
	if (count == 0 || size == 0)
	{
		ptr = malloc(0);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (a < count * size)
	{
		ptr[a] = 0;
		a++;
	}
	return (ptr);
}
