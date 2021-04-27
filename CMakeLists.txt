cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell srcs/main.c srcs/parse/parse.c srcs/logic/execute.c srcs/logic/cmd_echo.c srcs/logic/signal_handlers.c srcs/logic/cmd_cd.c srcs/logic/cmd_other.c srcs/logic/cmd_pwd.c srcs/logic/cmd_export.c srcs/parse/get_pwd_env.c srcs/parse/get_echo.c srcs/parse/get_cd.c srcs/parse/get_export.c srcs/parse/get_unset.c srcs/parse/utils.c srcs/parse/dollar.c srcs/logic/cmd_unset.c srcs/logic/cmd_exit.c srcs/logic/cmd_env.c)

include_directories(includes)
include_directories(libft/includes)

add_library(ft
		libft/includes/libft.h
		libft/includes/get_next_line.h
		libft/srcs/ft_atoi.c
		libft/srcs/ft_bzero.c
		libft/srcs/ft_calloc.c
		libft/srcs/ft_hexstr.c
		libft/srcs/ft_isalnum.c
		libft/srcs/ft_isalpha.c
		libft/srcs/ft_isascii.c
		libft/srcs/ft_isdigit.c
		libft/srcs/ft_isprint.c
		libft/srcs/ft_itoa.c
		libft/srcs/ft_lstadd_back.c
		libft/srcs/ft_lstadd_front.c
		libft/srcs/ft_lstclear.c
		libft/srcs/ft_lstdelone.c
		libft/srcs/ft_lstiter.c
		libft/srcs/ft_lstlast.c
		libft/srcs/ft_lstmap.c
		libft/srcs/ft_lstnew.c
		libft/srcs/ft_lstsize.c
		libft/srcs/ft_max.c
		libft/srcs/ft_memccpy.c
		libft/srcs/ft_memchr.c
		libft/srcs/ft_memcmp.c
		libft/srcs/ft_memcpy.c
		libft/srcs/ft_memmove.c
		libft/srcs/ft_memset.c
		libft/srcs/ft_nbrlen.c
		libft/srcs/ft_putchar_fd.c
		libft/srcs/ft_putchar.c
		libft/srcs/ft_putendl_fd.c
		libft/srcs/ft_putnbr_fd.c
		libft/srcs/ft_putnbr.c
		libft/srcs/ft_putstr_fd.c
		libft/srcs/ft_putstr.c
		libft/srcs/ft_split.c
		libft/srcs/ft_strchr.c
		libft/srcs/ft_strdup.c
		libft/srcs/ft_strjoin.c
		libft/srcs/ft_strlcat.c
		libft/srcs/ft_strlcpy.c
		libft/srcs/ft_strlen.c
		libft/srcs/ft_strmapi.c
		libft/srcs/ft_strncmp.c
		libft/srcs/ft_strnstr.c
		libft/srcs/ft_strrchr.c
		libft/srcs/ft_strtrim.c
		libft/srcs/ft_substr.c
		libft/srcs/ft_tolower.c
		libft/srcs/ft_toupper.c
		libft/srcs/get_next_line.c
		libft/srcs/ft_isspace.c
		libft/srcs/get_next_line_utils.c includes/minishell.h libft/srcs/ft_lsttoarr.c)

target_link_libraries(minishell LINK_PUBLIC termcap)

target_link_libraries(minishell LINK_PUBLIC ft)
