/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:21:05 by lucferna          #+#    #+#             */
/*   Updated: 2021/10/15 01:15:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_this(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*find_and_save(char **ptr)
{
	char	*new;
	char	*hold;
	int		i;

	i = 0;
	while ((*ptr)[i] && (*ptr)[i] != '\n')
		i++;
	hold = *ptr;
	new = create_and_dup(hold, i + 1);
	*ptr = ft_strdup(&hold[i + 1]);
	free_this(&hold);
	return (new);
}

static int	call_read(int fd, char *buffer, char **stt_ptr)
{
	char	*temp;
	int		n_read;

	n_read = 1;
	while (!ft_strchr(*stt_ptr, '\n') && n_read)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1)
			return (-1);
		buffer[n_read] = '\0';
		temp = *stt_ptr;
		*stt_ptr = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (n_read);
}

static char	*begin_gnl(int fd, char *buffer, char **stt_ptr)
{
	char	*temp;
	int		n_read;

	if (ft_strchr(*stt_ptr, '\n'))
		return (find_and_save(stt_ptr));
	n_read = call_read(fd, buffer, stt_ptr);
	if ((n_read == 0 || n_read == -1) && !**stt_ptr)
	{
		free_this(stt_ptr);
		return (NULL);
	}
	if (ft_strchr(*stt_ptr, '\n'))
		return (find_and_save(stt_ptr));
	else if (!ft_strchr(*stt_ptr, '\n') && **stt_ptr)
	{
		temp = ft_strdup(*stt_ptr);
		free_this(stt_ptr);
		return (temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stt_ptr[OPEN_MAX + 1];
	char		*buffer;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!stt_ptr[fd])
		stt_ptr[fd] = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	temp = begin_gnl(fd, buffer, &stt_ptr[fd]);
	free(buffer);
	return (temp);
}
