/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:29:14 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/21 20:23:44 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	line = NULL;
	bytes_read = 1;
	if (!buffer[0])
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
			buffer[bytes_read] = '\0';
	}
	while (bytes_read > 0)
	{
		if (nl_pos(buffer) != 0)
			return (join(line, buffer));
		line = join(line, buffer);
		if (line == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (handle_error(line, bytes_read));
		buffer[bytes_read] = '\0';
	}
	return (NULL);
}

/* #include <fcntl.h>
#include <stdio.h>
#include "test.txt"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
} */