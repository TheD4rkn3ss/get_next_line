/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferna <lucferna@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:04:22 by lucferna          #+#    #+#             */
/*   Updated: 2021/10/14 20:30:18 by lucferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
/**
 * @brief Create a string with same content as '*src' up to 'size' bytes.
 *
 * @param src The source string.
 * @param size How many bytes it will have.
 * @return char* The new string created.
 */
char	*create_and_dup(const char *src, size_t size);
char	*ft_strchr(const char *ptr, int c);

#endif
