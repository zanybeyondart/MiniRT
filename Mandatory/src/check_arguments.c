/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:02:24 by user              #+#    #+#             */
/*   Updated: 2024/09/14 03:34:45 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_objects	*check_arguments(int ac, char **av)
{
	t_objects	*objects;
	char		*file_path;

	file_path = ft_smart_malloc(ft_strlen("./Mandatory/src/scenes/")
			+ ft_strlen(av[1]) + 1);
	ft_strcpy(file_path, "./Mandatory/src/scenes/");
	ft_strcat(file_path, av[1]);
	objects = ft_smart_malloc(sizeof(t_objects));
	if (ac == 2 && av[1] && read_file(file_path, objects))
	{
		free(file_path);
		return (objects);
	}
	free(file_path);
	free(objects);
	printf("Error :Check Arguments\n");
	return (NULL);
}
