/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:29:16 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/14 12:33:49 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	strlen(char *str)
{
	unsigned int len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

unsigned int	nl_index(char *buffer)
{
	unsigned int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
void	rewrite_buffer(char *buffer, unsigned int i)
{
	
}
char	*join(char *line, char *buffer)
{
	int		len_line;
	char	*str;
	int		i;
	
	len_line = ft_strlen(line);
	if (line == NULL)
		str = malloc(sizeof(char) * (nl_index(buffer) + 2));
	else
		str = malloc(sizeof(char) * (len_line + ft_strlen(buffer) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (line[i++])
		str[i - 1] = line[i - 1];
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[len_line + i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		str[len_line + i] = buffer[i];
	rewrite_buffer(buffer, i);	
	return (free(line), str[len_line + i] = '\0', str);
}

char	*handle_error(void?)
{
	return (NULL);
}
