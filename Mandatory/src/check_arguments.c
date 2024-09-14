/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:02:24 by user              #+#    #+#             */
/*   Updated: 2024/09/14 15:06:14 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_arguments(int ac, char **av)
{
	t_objects	*objects;
	char		*file_path;

	file_path = ft_smart_malloc(ft_strlen("./Mandatory/src/scenes/")
			+ ft_strlen(av[1]) + 1);
	ft_strcpy(file_path, "./Mandatory/src/scenes/");
	ft_strcat(file_path, av[1]);
	objects = ft_smart_malloc(sizeof(t_objects));
	get_objects(objects, 1);
	if (ac == 2 && av[1] && read_file(file_path, objects))
	{
		free(file_path);
		return (0);
	}
	free(file_path);
	free(objects);
	printf("Error :Check Arguments\n");
	return (1);
}
