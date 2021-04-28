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
# include <termcap.h>
# include <fcntl.h>

# define CMD_OTHER 0
# define CMD_ECHO 1
# define CMD_CD 2
# define CMD_PWD 3
# define CMD_EXPORT 4
# define CMD_UNSET 5
# define CMD_ENV 6
# define CMD_EXIT 7

typedef struct s_parse
{
	int			command_id;
	t_list		*argv;
	char		**env;
	char		*file_out;
	char		*file_in;
	int			append_output;
}				t_parse;

//	Logic
void	execute_command_line(t_parse *parse, char ***env);

void	cmd_other(t_parse *parse, char **env);
void	cmd_echo(t_parse *parse);
void	cmd_cd(t_list *argv, char ***env);
void	cmd_pwd(void);
void	cmd_export(t_list *argv, char ***env);
void	cmd_unset(t_list *argv, char ***env);
void	cmd_env(char **env);
void	cmd_exit(t_list *argv);

void	insert_env(char *key, char *new_env, char ***env);
char	*get_env(char *key, char **env);

void	sigint_handler(int sig);
void	sigquit_handler(int sig);

//	Parse
void	parse_line(char *command_line, t_parse *parse);
void	ft_get_pwd_env_exit(t_parse *parse, int id);
void	ft_get_echo(t_parse *parse, char **str);
void	ft_get_cd(t_parse *parse, char **str);
void	ft_get_export(t_parse *parse, char **str);
void	ft_get_unset(t_parse *parse, char **str);
void	ft_get_exit(t_parse *parse, char **str);
void	ft_read_line(char **str, t_parse *parse);
char	*ft_for_print(char **str, t_parse *parse, char *ch);
int		ft_strchar_int(const char *str, char *line);
void	ft_push_argv(char *str, t_parse *parse, int n);
void	ft_dollar(char **str, t_parse *parse, int n);
void	ft_quote(char **str, t_parse *parse, int n);
void	ft_wquote(char **str, t_parse *parse, int n, int num_quote);

#endif
