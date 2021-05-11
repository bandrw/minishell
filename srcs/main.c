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

static void	read_line(char *str, char *command_line, t_history *history)
{
	int	l;
	int	pos;
	int	command_nbr;

	command_nbr = history->current;
	pos = 0;
	ft_bzero(command_line, sizeof(char) * 2048);
	while (str[0] != '\n' && str[0] != '\4')
	{
		l = read(0, str, 100);
		str[l] = 0;
		if (ft_strcmp(str, "\e[A") == 0 && command_nbr > 0) // Up
		{
			command_nbr--;
			tputs(restore_cursor, 1, (int (*)(int)) ft_putchar);
			tputs(tgoto(tgetstr("DC", 0), 0, ft_strlen(command_line)), 1, (int (*)(int)) ft_putchar);
			tputs(tgetstr("ed", 0), 1, (int (*)(int)) ft_putchar);
			ft_putstr(history->content[command_nbr]);
			pos = ft_strlen(history->content[command_nbr]);
			ft_strlcpy(command_line, history->content[command_nbr], pos + 1);
		}
		else if (ft_strcmp(str, "\e[B") == 0 && command_nbr < history->current) // Down
		{
			command_nbr++;
			tputs(restore_cursor, 1, (int (*)(int)) ft_putchar);
			tputs(tgoto(tgetstr("DC", 0), 0, ft_strlen(command_line)), 1, (int (*)(int)) ft_putchar);
			tputs(tgetstr("ed", 0), 1, (int (*)(int)) ft_putchar);
			ft_putstr(history->content[command_nbr]);
			pos = ft_strlen(history->content[command_nbr]);
			ft_strlcpy(command_line, history->content[command_nbr], pos + 1);
		}
		else if (ft_strcmp(str, "\e[C") == 0 && pos < ft_strlen(command_line)) // Right
		{
			write(1, str, l);
			pos++;
		}
		else if (ft_strcmp(str, "\e[D") == 0 && pos > 0) // Left
		{
			write(1, str, l);
			pos--;
		}
		else if (*str == 127) // Backspace
		{
			if (pos > 0)
			{
				pos--;
				ft_memmove(command_line + pos, command_line + pos + 1, ft_strlen(command_line + pos + 1) + 1);
				tputs(cursor_left, 1, (int (*)(int)) ft_putchar);
				tputs(tgetstr("dc", 0), 1, (int (*)(int)) ft_putchar);
			}
		}
		else if (str[1] == 0 && str[0] != '\n')
		{
			tputs(restore_cursor, 1, (int (*)(int)) ft_putchar);
			tputs(tgoto(tgetstr("DC", 0), 0, ft_strlen(command_line)), 1, (int (*)(int)) ft_putchar);
			tputs(tgetstr("ed", 0), 1, (int (*)(int)) ft_putchar);
			ft_memmove(command_line + pos + 1, command_line + pos, ft_strlen(command_line + pos + 1) + 1);
			command_line[pos] = *str;
			ft_putstr(command_line);
			tputs(tgoto(tgetstr("ch", 0), 0, pos + 1 + (int)ft_strlen("minishell$ ")), 1, (int (*)(int)) ft_putchar);
			pos += 1;
		}
	}
	if (str[0] != '\4')
		ft_putchar('\n');
	if (*command_line != '\0') // if not empty
		history_add(history, command_line);
}

#define DEBUG 1
#if DEBUG
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
		parse_line(command_line, argc, argv, &env);
		free(command_line);
	}
}
#else
int	main(int argc, char **argv, char **env)
{
	char		str[128];
	char		*command_line;
	t_history	history;

	ft_bzero(&g_state, sizeof(g_state));
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	termcap_init();
	env = arr_realloc(env);
	sort_arr(env);
	history.size = 10;
	history.content = (char **)malloc(sizeof(char *) * history.size);
	history.current = 0;
	while (1)
	{
		command_line = (char *)malloc(sizeof(char) * 2048);
		ft_putstr("\033[35mminishell$ \033[0m");
		str[0] = 0;
		tputs(save_cursor, 1, (int (*)(int)) ft_putchar);
		read_line(str, command_line, &history);
		if (*str == '\4')
		{
			ft_putendl_fd("exit", 1);
			return (0);
		}
		printf("Received: \"%s\"\n", command_line);
		parse_line(command_line, argc, argv, &env);
		free(command_line);
	}
}
#endif
