/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:29:08 by mtashrif          #+#    #+#             */
/*   Updated: 2024/09/15 03:09:33 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../gnl/get_next_line.h"

int	is_valid_type(char *test)
{
	int	i;

	i = 0;
	while ((test[i] == ' ' || test[i] == '\t') && test[i] != '\0')
		i++;
	if (test[i] == '\0')
		return (0);
	if ((test[i] == 'A' || test[i] == 'C' || \
		test[i] == 'L') && (ft_isspace(test[i + 1])))
		return (1);
	if ((test[i] == 's' && test[i + 1] == 'p') && (ft_isspace(test[i + 2])))
		return (1);
	if ((test[i] == 'p' && test[i + 1] == 'l') && (ft_isspace(test[i + 2])))
		return (1);
	if ((test[i] == 'c' && test[i + 1] == 'y') && (ft_isspace(test[i + 2])))
		return (1);
	return (0);
}

int	is_valid_line_format(char *l)
{
	int	i;

	i = 0;
	while (ft_isspace(l[i]))
		i++;
	if (l[i] == '\0')
		return (0);
	if (ft_strncmp(l + i, "A", 1) == 0 || \
		ft_strncmp(l + i, "C", 1) == 0 || ft_strncmp(l + i, "L", 1) == 0)
		i += 1;
	else if (ft_strncmp(l + i, "sp", 2) == 0 || \
		ft_strncmp(l + i, "pl", 2) == 0 || ft_strncmp(l + i, "cy", 2) == 0)
		i += 2;
	else
		return (0);
	while (ft_isspace(l[i]))
		i++;
	while (l[i] != '\0')
	{
		if (!ft_isspace(l[i]) && !ft_isdigit(l[i]) && \
			l[i] != ',' && l[i] != '-' && l[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int	read_test(char *test)
{
	int	i;

	i = 0;
	while ((test[i] == ' ' || test[i] == '\t') && test[i] != '\0')
		i++;
	if (!is_valid_type(test))
	{
		printf("Incorrect type in the file -> %c \n", test[i]);
		return (1);
	}
	if (test[i] == 'A' && check_ambient(test))
		return (1);
	if (test[i] == 'C' && check_camera(test))
		return (1);
	if (test[i] == 'L' && check_light(test))
		return (1);
	if (test[i] == 's' && test[i + 1] == 'p' && check_sphere(test))
		return (1);
	if (test[i] == 'p' && test[i + 1] == 'l' && check_plane(test))
		return (1);
	if (test[i] == 'c' && test[i + 1] == 'y' && check_cylinder(test))
		return (1);
	return (0);
}

int	read_file_test(int fd)
{
	char	*test;

	test = get_next_line(fd);
	if (check_test(test) == 1)
		return (1);
	while (test)
	{
		if (!empty_line(test) && (!is_valid_line_format(test) \
		|| read_test(test) != 0))
		{
			if (!is_valid_line_format(test))
				printf("Error: Invalid line format or unknown type: %s", test);
			free(test);
			return (1);
		}
		free(test);
		test = get_next_line(fd);
	}
	free(test);
	return (0);
}

int	read_file(char *readfile)
{
	int	fd;

	fd = open(readfile, O_RDONLY);
	if (check_fd(fd) == 1)
		return (1);
	if (read_file_test(fd) == 1)
	{
		close(fd);
		return (1);
	}
	else
		return (0);
}
