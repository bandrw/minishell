# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/15 22:56:24 by kfriese           #+#    #+#              #
#    Updated: 2021/05/15 22:56:25 by kfriese          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_DIR = libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

HEADERS_DIR = includes
OBJ_DIR = obj
OBJ_DIR_LOGIC = obj/logic
OBJ_DIR_PARSE = obj/parse
SRCS_DIR = srcs
HEADER_FILES = minishell.h

FLAGS = -Wall -Wextra -Werror
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft -I$(LIBFT_DIR)/includes
HEADERS = $(addprefix $(HEADERS_DIR)/, $(HEADER_FILES))

FILES = main.c \
		logic/execute.c \
		logic/cmd_echo.c \
		logic/signal_handlers.c \
		logic/cmd_cd.c \
		logic/cmd_other.c \
		logic/cmd_pwd.c \
		logic/cmd_export.c \
		logic/cmd_unset.c \
		logic/cmd_exit.c \
		logic/cmd_env.c \
		logic/logic_utils.c \
		logic/get_fd.c \
		logic/history.c \
		logic/logic_clean.c \
		logic/logic_errors.c \
		logic/termcap.c \
		parse/parse.c \
		parse/get_pwd_env.c \
		parse/get_echo.c \
		parse/get_cd.c \
		parse/get_export.c \
		parse/get_unset.c \
		parse/utils.c \
		parse/dollar.c \
		parse/get_exit.c \
		parse/quote.c \
		parse/get_redirection.c \
		parse/get_other.c \
		parse/parse_loop.c \
		parse/preparse.c \
		parse/escape.c \
		parse/parse_utils.c \
		parse/quote_utils.c

SRCS = $(addprefix $(SRCS_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all: $(OBJ_DIR) $(OBJ_DIR_LOGIC) $(OBJ_DIR_PARSE) build_libft build_minishell $(NAME)
	@echo "\033[44m ✔︎      Done      ✔︎ \033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR_LOGIC):
	@mkdir -p $(OBJ_DIR_LOGIC)

$(OBJ_DIR_PARSE):
	@mkdir -p $(OBJ_DIR_PARSE)

$(NAME): $(LIBFT_NAME) $(OBJ)
	gcc -o $(NAME) -ltermcap -I$(HEADERS_DIR) $(LIBFT_FLAGS) $(OBJ)

build_libft:
	@echo "\033[44m ⏤  Building libft ⏤  \033[0m"
	@make -C $(LIBFT_DIR)
	@echo "\033[44m ✔︎      Done      ✔︎ \033[0m\n"

build_minishell:
	@echo "\033[44m ⏤  Building minishell ⏤  \033[0m"

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	gcc $(FLAGS) -I$(HEADERS_DIR) -I$(LIBFT_DIR)/includes -c $< -o $@

$(OBJ_DIR)/parse/%.o: $(SRCS_DIR)/parse/%.c $(HEADERS)
	gcc $(FLAGS) -I$(HEADERS_DIR) -I$(LIBFT_DIR)/includes -c $< -o $@

$(OBJ_DIR)/logic/%.o: $(SRCS_DIR)/logic/%.c $(HEADERS)
	gcc $(FLAGS) -I$(HEADERS_DIR) -I$(LIBFT_DIR)/includes -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: bonus
