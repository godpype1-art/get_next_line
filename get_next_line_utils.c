/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:29:16 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/14 16:08:08 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

unsigned int	nl_index(char *buffer)
{
	unsigned int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i++] == '\n')
			return (i);
	}
	return (0);
}

void	rewrite_buffer(char *buffer, unsigned int i)
{
	unsigned int	j;

	j = 0;
	if (buffer[i] == '\n')
	{
		while (buffer[i + j] && j <= i)
		{
			buffer[j] = buffer[i + j];
			j++;
		}
		buffer[j] = '\0';
	}
	else
	{
		buffer[0] = '\0';
	}
}

char	*join(char *line, char *buffer)
{
	int		len_line;
	char	*str;
	int		i;
	int		j;

	len_line = ft_strlen(line);
	if (nl_index(buffer))
		str = malloc(sizeof(char) * (len_line + nl_index(buffer) + 1));
	else
		str = malloc(sizeof(char) * (len_line + ft_strlen(buffer) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (line && line[i])
		str[i++] = line[j++];
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
		str[i++] = buffer[j++];
	if (buffer[j] == '\n')
		str[i] = '\n';
	str[i + 1] = '\0';
	rewrite_buffer(buffer, i);
	free(line);
	return (str);
}

char	*handle_error(char *line)
{
	free(line);
	return (NULL);
}
/* int main(void)
{
	char line[] = "hello ";
	char buffer[] = "world";

	printf("join output = %s\n", join(line, buffer));
	return 0;
}
 */