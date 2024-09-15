/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:11:38 by mtashrif          #+#    #+#             */
/*   Updated: 2024/09/15 03:47:55 by zvakil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../../inc/minirt.h"

int	check_fd(int fd)
{
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	return (0);
}

int	check_test(char *test)
{
	if (!test)
	{
		printf("Error: The file is empty \n");
		return (1);
	}
	return (0);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'\
		|| line[i] == '\n' || line[i] == '\r'))
		i++;
	return (line[i] == '\0');
}

int	camera_error(void)
{
	printf("Error: Camera should only be added once \n");
	return (1);
}
