/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtashrif <mtashrif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:11:38 by mtashrif          #+#    #+#             */
/*   Updated: 2024/09/14 19:23:08 by mtashrif         ###   ########.fr       */
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
