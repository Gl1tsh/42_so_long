/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:38:47 by nagiorgi          #+#    #+#             */
/*   Updated: 2023/12/30 18:52:44 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//=================================
#include "libft.h"


void	*reset_mem_gnl(t_gnl *gnl)
{
	free(gnl->buffer);
	gnl->buffer = NULL;
	gnl->after_new_line = NULL;
	gnl->bytes_read = 0;
	return (NULL);
}

char	*fill_buffer(int fd, t_gnl *gnl)
{
	int		read_result;
	char	*newline_found;

	while (1)
	{
		read_result = read(fd, gnl->buffer + gnl->bytes_read, BUFFER_SIZE);
		if (read_result < 0)
			return (reset_mem_gnl(gnl));
		if (read_result == 0)
		{
			if (gnl->bytes_read == 0)
				return (reset_mem_gnl(gnl));
			gnl->after_new_line = gnl->buffer + gnl->bytes_read;
			return (ft_strndup(gnl->buffer, gnl->bytes_read));
		}
		gnl->bytes_read = gnl->bytes_read + read_result;
		newline_found = ft_memchr(gnl->buffer, '\n', gnl->bytes_read);
		if (newline_found != NULL)
		{
			gnl->after_new_line = newline_found + 1;
			return (ft_strndup(gnl->buffer, (newline_found - gnl->buffer) + 1));
		}
	}
}

char	*get_next_line(int fd)
{
	static t_gnl	all_gnl[OPEN_MAX]
		= {[0 ...OPEN_MAX - 1] = {NULL, NULL, 0}};
	t_gnl			*gnl;
	size_t			new_bytes_read;
	char			*newline_found;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	gnl = &all_gnl[fd];
	if (gnl->buffer == NULL)
		gnl->buffer = malloc(sizeof(char) * 2000000);
	if (gnl->after_new_line != NULL)
	{
		new_bytes_read = gnl->bytes_read - (gnl->after_new_line - gnl->buffer);
		ft_memmove(gnl->buffer, gnl->after_new_line, new_bytes_read);
		gnl->bytes_read = new_bytes_read;
		newline_found = ft_memchr(gnl->buffer, '\n', gnl->bytes_read);
		if (newline_found != NULL)
		{
			gnl->after_new_line = newline_found + 1;
			return (ft_strndup(gnl->buffer, (newline_found - gnl->buffer) + 1));
		}
	}
	return (fill_buffer(fd, gnl));
}

/*
int _read(int fd, char *buffer, int count)
{
  if (cursor >= sizeof(content)) return 0;
  if ((cursor + count) > sizeof(content)) count = sizeof(content) - cursor;
  memcpy(buffer, content + cursor, count);
  cursor += count;
  return count;
}

#include <stdio.h>
int main()
{
    char *line;
    while ((line = get_next_line(0)))
    {
        printf("%s", line);
    }
    return 0;
}
*/