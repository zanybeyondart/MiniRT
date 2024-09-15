/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:02:24 by user              #+#    #+#             */
/*   Updated: 2024/09/15 04:04:19 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_rt(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
		i++;
	if ((str[i - 1] && str[i - 1] == 't') \
		&& (str[i - 2] && str[i - 2] == 'r') \
		&& (str[i - 3] && str[i - 3] == '.'))
		return (0);
	else
	{
		printf("Error: Please provide file name with correct extension\n");
		return (1);
	}
}

int	check_arguments(int ac, char **av)
{
	char		*file_path;

	if (av && av[1])
	{
		file_path = ft_smart_malloc(ft_strlen("./Mandatory/src/scenes/")
				+ ft_strlen(av[1]) + 1);
		ft_strcpy(file_path, "./Mandatory/src/scenes/");
		ft_strcat(file_path, av[1]);
	}
	get_objects(NULL, 1);
	if (ac == 2 && av[1] && !check_rt(av[1]) && !read_file(file_path))
	{
		free(file_path);
		return (0);
	}
	free (file_path);
	if (ac < 2)
		printf("Too few arguments \n");
	else if (ac > 2)
		printf("Too many arguments \n");
	// printf("Error: Check Arguments\n");
	return (1);
}
