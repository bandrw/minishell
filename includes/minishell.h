/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:23:36 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/12 22:23:37 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <sys/wait.h>

# define CMD_OTHER 0
# define CMD_ECHO 1
# define CMD_CD 2

typedef struct	s_parse
{
	int			command_id;
	char		**argv;
}				t_parse;

void	parse_line(char *command_line, t_parse *parse);
void	execute_command_line(t_parse *parse, char **env);
void	ft_echo(char **argv, char **env);
void	ft_cd(char **argv, char **env);
void	sigint_handler(int sig);
void	sigquit_handler(int sig);

#endif
