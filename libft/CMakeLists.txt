cmake_minimum_required(VERSION 3.17)
project(libft C)

set(CMAKE_C_STANDARD 99)

add_library(ft
		includes/libft.h
		includes/get_next_line.h
		srcs/ft_atoi.c
		srcs/ft_bzero.c
		srcs/ft_calloc.c
		srcs/ft_hexstr.c
		srcs/ft_isalnum.c
		srcs/ft_isalpha.c
		srcs/ft_isascii.c
		srcs/ft_isdigit.c
		srcs/ft_isprint.c
		srcs/ft_itoa.c
		srcs/ft_lstadd_back.c
		srcs/ft_lstadd_front.c
		srcs/ft_lstclear.c
		srcs/ft_lstdelone.c
		srcs/ft_lstiter.c
		srcs/ft_lstlast.c
		srcs/ft_lstmap.c
		srcs/ft_lstnew.c
		srcs/ft_lstsize.c
		srcs/ft_max.c
		srcs/ft_memccpy.c
		srcs/ft_memchr.c
		srcs/ft_memcmp.c
		srcs/ft_memcpy.c
		srcs/ft_memmove.c
		srcs/ft_memset.c
		srcs/ft_nbrlen.c
		srcs/ft_putchar_fd.c
		srcs/ft_putchar.c
		srcs/ft_putendl_fd.c
		srcs/ft_putnbr_fd.c
		srcs/ft_putnbr.c
		srcs/ft_putstr_fd.c
		srcs/ft_putstr.c
		srcs/ft_split.c
		srcs/ft_strchr.c
		srcs/ft_strdup.c
		srcs/ft_strjoin.c
		srcs/ft_strlcat.c
		srcs/ft_strlcpy.c
		srcs/ft_strlen.c
		srcs/ft_strmapi.c
		srcs/ft_strncmp.c
		srcs/ft_strnstr.c
		srcs/ft_strrchr.c
		srcs/ft_strtrim.c
		srcs/ft_substr.c
		srcs/ft_tolower.c
		srcs/ft_toupper.c
		srcs/get_next_line.c
		srcs/get_next_line_utils.c)

include_directories(includes)
