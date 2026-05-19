/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falves-e <falves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:29:11 by falves-e          #+#    #+#             */
/*   Updated: 2026/05/19 18:25:24 by falves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char			*get_next_line(int fd);
unsigned int	nl_index(char *buffer);
unsigned int	ft_strlen(char *str);
char			*join(char *line, char *buffer);
char			*handle_error(char *line);
void			rewrite_buffer(char *buffer);

#endif