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
# include <string.h>
# include <errno.h>
#include <termcap.h>

# define CMD_OTHER 0
# define CMD_ECHO 1
# define CMD_CD 2
# define CMD_PWD 3
# define CMD_EXPORT 4
# define CMD_UNSET 5
# define CMD_ENV 6
# define CMD_EXIT 7

typedef struct	s_parse
{
	int			command_id;
	t_list		*argv;
}				t_parse;

void	parse_line(char *command_line, t_parse *parse);
void	execute_command_line(t_parse *parse, char **env);

void	ft_other(t_parse *parse, char **env);
void	ft_echo(t_list *argv, char **env);
void	ft_cd(t_list *argv);
void	ft_pwd(void);
void	ft_export(t_list *argv, char **env);

//char	*get_env(char *s, char **env);

void	sigint_handler(int sig);
void	sigquit_handler(int sig);

void	ft_get_pwd_env(t_parse *parse, int id);
void 	ft_get_echo(t_parse *parse, char **str);
void	ft_get_cd(t_parse *parse, char *str);
void	ft_get_export(t_parse *parse, char *str);
void	ft_get_unset(t_parse *parse, char *str);
void	ft_get_exit(t_parse *parse, char *str);
void	ft_read_line(char **str, t_parse *parse);
void	ft_for_print(char **str, t_parse *parse, int *ac);
int 	ft_strchr_int(const char *str, char *line);

#endif
