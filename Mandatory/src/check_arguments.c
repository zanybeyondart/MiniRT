/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:02:24 by user              #+#    #+#             */
/*   Updated: 2024/07/17 13:35:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_arguments(int ac, char **av)
{
	char **useles;
	if (ac < 2)
		return (1);
	useles = av;
	useles = NULL;
	useles = ft_smart_malloc(10);
	free (useles);
	return (0);
}
