/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:00:52 by eblancha          #+#    #+#             */
/*   Updated: 2025/01/09 08:58:19 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_strchr(const char *string, int character);
size_t	gnl_strlen(char *string);
size_t	gnl_strlcpy(char *dest, const char *source, size_t dest_size);
char	*gnl_strjoin(char *s1, char *s2);
char	*allocate_string(size_t size);

#endif
