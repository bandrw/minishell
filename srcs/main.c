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
	int		n;
	char	*command_line;
	t_parse	parse;

	while (1)
	{
		ft_putstr("minishell$ ");
		n = get_next_line(0, &command_line);
		if (n == 0)
			ft_putchar_fd('\n', 2);
		if (n != 1)
		{
			ft_putendl_fd("Error: Gnl", 2);
			return (1);
		}
		parse_line(command_line, &parse);
		execute_command_line(&parse, env);
	}
}
