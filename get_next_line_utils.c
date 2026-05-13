/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:29:16 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/13 20:43:59 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	strlen(char *str)
{
	int len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	nl_index(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*join(char *line, char *buffer)
{
	int		len_line;
	char	*str;
	int		i;
	
	len_line = ft_strlen(line);
	if (!*line)
		str = malloc(sizeof(char) * (len_line + nl_index(buffer) + 2));
	else
		str = malloc(sizeof(char) * (len_line + ft_strlen(buffer) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	i = 0;
	while (str[len_line + i - 1] && buffer[i])
	{
		str[len_line + i] = buffer[i];
		i++;
	}
	rewrite_buffer(buffer);	
	return (str[len_line + i] = '\0', str);
}

char	*handle_error(void?)
{
	return (NULL);
}
