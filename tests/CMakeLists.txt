cmake_minimum_required(VERSION 3.17)

set(CMAKE_C_STANDARD 99)

add_library(minishell_lib
		../srcs/parse/parse.c
		../srcs/logic/execute.c
		../srcs/logic/cmd_echo.c
		../srcs/logic/signal_handlers.c
		../srcs/logic/cmd_cd.c
		../srcs/logic/cmd_other.c
		../srcs/logic/cmd_pwd.c
		../srcs/logic/cmd_export.c
		../srcs/parse/get_pwd_env.c
		../srcs/parse/get_echo.c
		../srcs/parse/get_cd.c
		../srcs/parse/get_export.c
		../srcs/parse/get_unset.c
		../srcs/parse/utils.c
		../srcs/parse/dollar.c
		../srcs/logic/cmd_unset.c
		../srcs/logic/cmd_exit.c
		../srcs/logic/cmd_env.c
		../srcs/parse/get_exit.c
		../srcs/logic/logic_utils.c
		../srcs/parse/quote.c
		../srcs/logic/get_fd.c
		../srcs/logic/history.c
		../srcs/parse/get_redirection.c
		../srcs/parse/get_other.c
        ../srcs/logic/logic_clean.c)

add_test(NAME parse_test_1
		COMMAND ./tests/parse_test_1
		WORKING_DIRECTORY .)

add_executable(parse_test_1 parse_test_1.c)

target_link_libraries(parse_test_1 LINK_PUBLIC ft)
target_link_libraries(parse_test_1 LINK_PUBLIC minishell_lib)


add_test(NAME parse_test_2
		COMMAND ./tests/parse_test_2
		WORKING_DIRECTORY .)

add_executable(parse_test_2 parse_test_2.c)

target_link_libraries(parse_test_2 LINK_PUBLIC ft)
target_link_libraries(parse_test_2 LINK_PUBLIC minishell_lib)
