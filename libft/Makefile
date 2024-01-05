# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 19:39:17 by nagiorgi          #+#    #+#              #
#    Updated: 2024/01/05 18:15:50 by nagiorgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Liste des fichiers source
SRCS = 	ft_memchr.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strtrim.c \
		ft_numbers.c \
		ft_print_str.c \
		ft_printf.c \
		get_next_line_bonus.c \
		get_next_line_utils.c \
		get_next_line_utils_bonus.c \
		get_next_line.c \
		$(wildcard *.c)

# Liste des fichiers objets
OBJS = $(SRCS:.c=.o)

# Nom du fichier d'en-tête
HEAD = libft.h

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Werror -Wextra -I.

# Nom de la bibliothèque
NAME = libft.a

CLEAN = rm -f

ARC = ar rcs

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Règle par défaut pour construire la bibliothèque
$(NAME): $(OBJS)
	@${ARC} $(NAME) $^

all:	$(NAME)

clean:
	@${CLEAN} ${OBJS}

fclean:	clean
	@${CLEAN} ${NAME}

re:	fclean	all
