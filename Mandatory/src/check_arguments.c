/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:02:24 by user              #+#    #+#             */
/*   Updated: 2024/09/15 03:09:53 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_arguments(int ac, char **av)
{
	char		*file_path;

	if (av[1])
	{
		file_path = ft_smart_malloc(ft_strlen("./Mandatory/src/scenes/")
				+ ft_strlen(av[1]) + 1);
		ft_strcpy(file_path, "./Mandatory/src/scenes/");
		ft_strcat(file_path, av[1]);
	}
	get_objects(NULL, 1);
	if (ac == 2 && av[1] && !read_file(file_path))
	{
		free(file_path);
		return (0);
	}
	free (file_path);
	printf("Error :Check Arguments\n");
	return (1);
}
