/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:00:17 by kfriese           #+#    #+#             */
/*   Updated: 2021/05/12 20:00:17 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	termcap_up(int *command_nbr, char *command_line, int *pos,
				t_history *history)
{
	(*command_nbr)--;
	tputs(restore_cursor, 1, (int (*)(int)) ft_putchar);
	tputs(tgoto(tgetstr("DC", 0), 0, ft_strlen(command_line)), 1,
		(int (*)(int)) ft_putchar);
	tputs(tgetstr("ed", 0), 1, (int (*)(int)) ft_putchar);
	ft_putstr(history->content[*command_nbr]);
	*pos = ft_strlen(history->content[*command_nbr]);
	ft_strlcpy(command_line, history->content[*command_nbr], *pos + 1);
}

void	termcap_down(int *command_nbr, char *command_line, int *pos,
					t_history *history)
{
	(*command_nbr)++;
	tputs(restore_cursor, 1, (int (*)(int)) ft_putchar);
	tputs(tgoto(tgetstr("DC", 0), 0, ft_strlen(command_line)), 1,
		(int (*)(int)) ft_putchar);
	tputs(tgetstr("ed", 0), 1, (int (*)(int)) ft_putchar);
	ft_bzero(command_line, sizeof(char) * 2048);
	ft_putstr(history->content[*command_nbr]);
	*pos = ft_strlen(history->content[*command_nbr]);
	ft_strlcpy(command_line, history->content[*command_nbr], *pos + 1);
}

void	termcap_backspace(int *pos, char *command_line)
{
	if (*pos > 0)
	{
		(*pos)--;
		ft_memmove(command_line + *pos, command_line + *pos + 1,
			ft_strlen(command_line + *pos + 1) + 1);
		tputs(cursor_left, 1, (int (*)(int)) ft_putchar);
		tputs(tgetstr("dc", 0), 1, (int (*)(int)) ft_putchar);
	}
}

void	termcap_input(char *command_line, int *pos, const char *str)
{
	tputs(restore_cursor, 1, (int (*)(int)) ft_putchar);
	tputs(tgoto(tgetstr("DC", 0), 0, ft_strlen(command_line)), 1,
		(int (*)(int)) ft_putchar);
	tputs(tgetstr("ed", 0), 1, (int (*)(int)) ft_putchar);
	ft_memmove(command_line + *pos + 1, command_line + *pos,
		ft_strlen(command_line + *pos + 1) + 1);
	command_line[*pos] = *str;
	ft_putstr(command_line);
	tputs(tgoto(tgetstr("ch", 0), 0, *pos + 1 + (int)ft_strlen("minishell$ ")),
		1, (int (*)(int)) ft_putchar);
	(*pos)++;
}

char	termcap_loop(int *command_nbr, int *pos, char *command_line,
				t_history *history)
{
	char	str[128];
	int		l;

	l = read(0, str, 100);
	str[l] = 0;
	if (ft_strcmp(str, "\e[A") == 0 && *command_nbr > 0)
		termcap_up(command_nbr, command_line, pos, history);
	else if (ft_strcmp(str, "\e[B") == 0 && *command_nbr < history->current)
		termcap_down(command_nbr, command_line, pos, history);
	else if (ft_strcmp(str, "\e[C") == 0 && *pos < ft_strlen(command_line))
	{
		write(1, str, l);
		(*pos)++;
	}
	else if (ft_strcmp(str, "\e[D") == 0 && *pos > 0)
	{
		write(1, str, l);
		(*pos)--;
	}
	else if (*str == 127)
		termcap_backspace(pos, command_line);
	else if (str[1] == 0 && str[0] != '\n')
		termcap_input(command_line, pos, str);
	return (str[0]);
}
