/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:29:14 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/08 13:11:12 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	int			i;
	static char	*saved;
	
	read(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			saved = substr(buffer, i + 1, (strlen(buffer) - i));
			if(saved == NULL)
				return(NULL);
			return (buffer);
		}
		i++;
	}
	saved = buffer;
	strlcat(saved, get_next_line(fd), BUFFER_SIZE);
	return (buffer);
}
