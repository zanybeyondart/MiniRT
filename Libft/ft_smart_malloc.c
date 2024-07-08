/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:51:33 by user              #+#    #+#             */
/*   Updated: 2024/07/08 15:54:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_smart_malloc(size_t size)
{
	void	*temp;

	temp = NULL;
	temp = malloc(size);
	if (temp == NULL)
	{
		printf("Program Failed : Memory Allocation\n");
		exit(1);
	}
	return (temp);
}
