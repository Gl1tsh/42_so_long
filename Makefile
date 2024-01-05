# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 18:42:23 by nagiorgi          #+#    #+#              #
#    Updated: 2024/01/05 17:12:55 by nagiorgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror -I./include -I./minilibx -I./libft
MLXDIR = ./minilibx
LIBFTDIR = ./libft
INCMLX = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -lm
INCLIBFT = -L$(LIBFTDIR) -lft

OBJDIR = obj/
SRCDIR = src/
SRCS = $(wildcard $(SRCDIR)*.c)
OBJS = $(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR) > /dev/null 2>&1
	@$(CC) -o $@ $^ $(FLAGS) $(INCMLX) $(INCLIBFT)
	@echo "\033[0;32mCompilation réussie ! Le jeu est prêt à être joué.\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) -c -o $@ $< $(FLAGS)

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFTDIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
	@echo "\033[0;32mC'est propre\033[0m"

re: fclean all