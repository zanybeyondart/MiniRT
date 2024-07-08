/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:10:07 by zvakil            #+#    #+#             */
/*   Updated: 2023/08/06 14:26:28 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		a;
	t_list	*counter;

	a = 0;
	counter = lst;
	while (counter)
	{
		counter = counter->next;
		a++;
	}
	return (a);
}
