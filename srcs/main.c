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
	ft_bzero(command_line, sizeof(command_line));
	while (str[0] != '\n' && str[0] != '\4')
	{
		l = read(0, str, 100);
		str[l] = 0;
		if (ft_strcmp(str, "\e[A") == 0 && command_nbr > 0)
		{
			command_nbr--;
			tputs(restore_cursor, 1, (int (*)(int)) ft_putchar);
			tputs(tgetstr("ed", 0), 1, (int (*)(int)) ft_putchar);
			ft_putstr(history->content[command_nbr]);
			pos = ft_strlen(history->content[command_nbr]);
			ft_strlcpy(command_line, history->content[command_nbr], pos + 1);
		}
		else if (ft_strcmp(str, "\e[B") == 0 && command_nbr < history->current)
		{
			command_nbr++;
			tputs(restore_cursor, 1, (int (*)(int)) ft_putchar);
			tputs(tgetstr("ed", 0), 1, (int (*)(int)) ft_putchar);
			ft_putstr(history->content[command_nbr]);
			pos = ft_strlen(history->content[command_nbr]);
			ft_strlcpy(command_line, history->content[command_nbr], pos + 1);
		}
//		else if (ft_strcmp(str, "\e[C") == 0 && pos < 20) // cursor moving (it's hard)
//		{
//			write(1, str, l);
//			pos++;
//		}
//		else if (ft_strcmp(str, "\e[D") == 0 && pos > 0)
//		{
//			write(1, str, l);
//			pos--;
//		}
		else if (*str == 127)
		{
			if (pos > 0)
			{
				command_line[pos] = '\0';
				pos--;
				tputs(cursor_left, 1, (int (*)(int)) ft_putchar);
				tputs(tgetstr("dc", 0), 1, (int (*)(int)) ft_putchar);
			}
		}
		else if (str[1] == 0)
		{
			write(1, str, 1);
			command_line[pos] = *str;
			if (command_line[pos] == '\n')
				command_line[pos] = '\0';
			pos += 1;
		}
//		printf("%d: %d %d\n", l, str[0], str[1]);
	}
	if (*command_line != '\0')
		history_add(history, command_line);
}

int	main(int argc, char **argv, char **env)
{
	char		str[128];
	char		*command_line;
	t_list		*parse_list;
	t_history	history;

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
		printf("Received: \"%s\"\n", command_line);
		parse_list = 0;
		parse_line(command_line, &parse_list, env);
		execute_command_line(parse_list, &env);
		ft_lstclear(&parse_list, free);
		free(command_line);
		if (*str == '\4')
		{
			ft_putendl_fd("exit", 1);
			return (0);
		}
	}
}
