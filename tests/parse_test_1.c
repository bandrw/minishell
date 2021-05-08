#include "minishell.h"

t_state g_state;

static void	fatal(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int		main(int argc, char **argv, char **env)
{
	t_list *list;
	t_parse *parse;
	char	**argv_arr;

	list = parse_line("echo 123 | cat -e", argc, argv, &env);
	if (ft_lstsize(list) != 2)
		fatal("There are not 2 commands");

	// echo
	parse = list->content;
	if (parse->command_id != CMD_ECHO)
		fatal("Wrong command id");
	if (parse->pipe_info.pipe_to_next != 1)
		fatal("pipe_to_next fault");
	argv_arr = ft_lsttoarr(parse->argv);
	if (strcmp(argv_arr[0], "123") != 0 || argv_arr[1] != 0)
		fatal("Wrong argument");

	// cat
	parse = list->next->content;
	if (parse->command_id != CMD_OTHER)
		fatal("Wrong command id");
	if (parse->pipe_info.pipe_to_next != 0)
		fatal("pipe_to_next fault");
	argv_arr = ft_lsttoarr(parse->argv);
	if (strcmp(argv_arr[0], "cat") != 0 || strcmp(argv_arr[1], "-e") != 0 || argv_arr[2] != 0)
		fatal("Wrong argument");
	if (parse->pipe_info.fd_in == 0)
		fatal("Wrong fd_in");
	return (0);
}
