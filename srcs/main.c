/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:23:25 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/12 22:23:27 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_state	g_state;

static void	termcap_init(void)
{
	char			*term_name;
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	term_name = getenv("TERM");
	if (!term_name || tgetent(0, term_name) == -1)
	{
		ft_putendl_fd("Error: termcap", 2);
		exit(1);
	}
}

static void	main_init(char ***env, t_history *history, int argc, char **argv)
{
	ft_bzero(&g_state, sizeof(g_state));
	g_state.argc = argc;
	g_state.argv = argv;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	termcap_init();
	*env = arr_realloc(*env);
	sort_arr(*env);
	history->size = 10;
	history->content = (char **)malloc(sizeof(char *) * history->size);
	history->current = 0;
}

static char	read_line(char *command_line, t_history *history)
{
	int		pos;
	int		command_nbr;
	char	ch;

	command_nbr = history->current;
	pos = 0;
	ft_bzero(command_line, sizeof(char) * 2048);
	ch = 0;
	while (ch != '\n' && ch != '\4')
		ch = termcap_loop(&command_nbr, &pos, command_line, history);
	if (ch != '\4')
		ft_putchar('\n');
	if (*command_line != '\0')
		history_add(history, command_line);
	return (ch);
}

//int	main(int argc, char **argv, char **env)
//{
//	char		ch;
//	char		*command_line;
//	t_history	history;
//
//	main_init(&env, &history, argc, argv);
//	while (1)
//	{
//		command_line = (char *)malloc(sizeof(char) * 2048);
//		ft_putstr("\033[35mminishell$ \033[0m");
//		tputs(save_cursor, 1, (int (*)(int)) ft_putchar);
//		ch = read_line(command_line, &history);
//		if (ch == '\4')
//		{
//			ft_putendl_fd("\bexit", 1);
//			return (0);
//		}
//		parse_line(command_line, &env);
//		free(command_line);
//	}
//}

int	main(int argc, char **argv, char **env)
{
	int		n;
	char	*command_line;

	ft_bzero(&g_state, sizeof(g_state));
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	env = arr_realloc(env);
	sort_arr(env);
	while (1)
	{
		ft_putstr("\033[35mminishell$ \033[0m");
		n = get_next_line(0, &command_line);
		if (n == 0)
		{
			ft_putendl_fd("exit", 1);
			return (0);
		}
		if (n != 1)
		{
			ft_putendl_fd("Error: GNL", 2);
			return (1);
		}
		parse_line(command_line, &env);
		free(command_line);
	}
}
