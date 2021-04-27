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

int	main(int argc, char **argv, char **env)
{
//	// Termcap test
//	char buf[1024];
//	char buf2[30];
//	char *ap = buf2;
//	char *gotostr;
//
//	tgetent(buf, getenv("TERM"));
////	gotostr = tgetstr("cm", &ap);
//	gotostr = tgetstr("hey", &ap);
//	tputs(tgoto(gotostr, 20, 0), 1, (int (*)(int)) ft_putchar);
////	ft_putstr(tgoto(gotostr, 20, 0));
//	ft_putstr("Hello, world!\n");

	int		n;
	char	*command_line;
	t_parse	parse;

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
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
		ft_bzero(&parse, sizeof(parse));
		parse_line(command_line, &parse);
		execute_command_line(&parse, env);
		free(command_line);
	}
}
