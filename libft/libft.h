/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:39:09 by nagiorgi          #+#    #+#             */
/*   Updated: 2023/10/03 19:39:09 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl
{
	char	*buffer;
	char	*after_new_line;
	size_t	bytes_read;
}			t_gnl;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*get_next_line(int fd);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strndup(const char *str, size_t n);
int		ft_putnbr_10(long nb);
int		ft_putnbr_10_u(unsigned long nb);
int		ft_putnbr_16(unsigned long nb, int uppercase);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);

#endif
