/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:13:47 by coder             #+#    #+#             */
/*   Updated: 2021/10/15 01:15:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(s) + 1;
	new = malloc(size * sizeof(char));
	if (new)
	{
		while (s[i])
		{
			new[i] = s[i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	start = new;
	while (*s1)
	{
		*new++ = *s1++;
	}
	while (*s2)
	{
		*new++ = *s2++;
	}
	*new = '\0';
	return (start);
}

char	*create_and_dup(const char *src, size_t size)
{
	size_t	total;
	char	*new;

	total = 0;
	new = (char *)malloc((size + 1) * sizeof(char));
	while (total < size)
	{
		new[total] = src[total];
		total++;
	}
	new[total] = '\0';
	return (new);
}

char	*ft_strchr(const char *ptr, int c)
{
	while (*ptr)
	{
		if (*ptr == c)
		{
			return ((char *)ptr);
		}
		ptr++;
	}
	if (c == '\0' && *ptr == '\0')
		return ((char *)ptr);
	return (NULL);
}
