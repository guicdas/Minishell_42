# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 12:17:17 by helferna          #+#    #+#              #
#    Updated: 2024/02/26 14:00:48 by gcatarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = minishell
OS    = $(shell uname)
CC    = @cc
FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LFT   = libft/libft.a
INC   = -I./libft -I./include
SRC   = src/main.c src/parser/lexer.c src/clean/ft_free.c src/executor/executor.c \
		src/builtins/exec_builtin.c src/builtins/echo.c src/builtins/cd.c src/builtins/unset.c \
		src/builtins/env.c src/builtins/exit.c src/builtins/export.c src/builtins/pwd.c \
		src/utils/ft_utils.c src/signals/signals.c src/redirect/heredoc.c src/utils/ft_lists.c \
		src/redirect/redirect.c src/redirect/handle_files.c src/expander/expander.c \
		src/utils/ft_utils_2.c src/parser/quotes.c src/utils/ft_export_utils.c \
		src/errors/error.c src/utils/ft_utils_3.c src/utils/ft_utils_4.c src/expander/ft_expander_utils.c

OBJ   = $(patsubst src/%.c, obj/%.o, $(SRC))

all: $(MLX) $(LFT) obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I./include -lreadline -lncurses -o $@ $^ $(LFT) 
$(LFT):
	@make -sC libft

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -lreadline $(INC) -c $< -o $@
	@mkdir -p obj

clean:
	@make -sC libft clean
	@rm -rf $(OBJ) obj

fclean: clean
	@make -sC libft fclean
	@rm -rf $(NAME)

re: fclean all

r: 
	@make re && clear
	./minishell

# v: 
# 	make re && clear && valgrind ./minishell

v: re readline.supp
	clear
	@valgrind  --track-fds=yes --show-leak-kinds=all --leak-check=full --suppressions=readline.supp  ./minishell

readline.supp:
	@wget https://raw.githubusercontent.com/benjaminbrassart/minishell/master/readline.supp 2> /dev/null 1> /dev/null
.PHONY: all
