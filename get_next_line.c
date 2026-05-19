/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:29:14 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/19 18:51:13 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		b_read;
	char		*line;

	buffer[BUFFER_SIZE] = '\0';
	line = NULL;
	b_read = 1;
	if (!*buffer)
		b_read = read(fd, buffer, BUFFER_SIZE);
	while (b_read > 0)
	{
		if (nl_index(buffer))
			return (join(line, buffer));
		line = join(line, buffer);
		if (line == NULL)
			return (NULL);
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == 0)
			return (line);
		else if (b_read < 0)
			return (handle_error(line));
	}
	return (NULL);
}
