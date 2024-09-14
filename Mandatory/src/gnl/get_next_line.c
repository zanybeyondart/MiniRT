#include "get_next_line.h"

char	*print_line(char **temp)
{
	int		n_pos;
	char	*return_line;
	char	*str;

	if (!*temp)
		return (NULL);
	str = *temp;
	n_pos = 0;
	while (str[n_pos] && str[n_pos] != 10)
		n_pos++;
	if (str[n_pos] == 10)
		n_pos++;
	return_line = ft_strdup_gnl(str, n_pos);
	*temp = ft_strdup_gnl(str + n_pos, ft_strlen(str + n_pos));
	if (str)
		free(str);
	str = NULL;
	return (return_line);
}

static int	read_data(int fd, char **temp)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (-1);
	}
	buffer[bytes_read] = '\0';
	*temp = ft_strjoin_gnl(*temp, buffer);
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	int			bytes_read;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (free(temp), temp = NULL, NULL);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (free(temp), temp = NULL, NULL);
	if (have_n(temp))
		return (print_line(&temp));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read_data(fd, &temp);
		if (bytes_read == -1)
			return (free(temp), temp = NULL, NULL);
		if (have_n(temp))
			break ;
	}
	return (print_line(&temp));
}
