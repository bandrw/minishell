cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell srcs/main.c)

include_directories(libft/includes)

find_library(FT ft libft)
target_link_libraries(minishell LINK_PUBLIC ${FT})
