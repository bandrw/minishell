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
# include <sys/stat.h>
# include <string.h>
# include <errno.h>
# include <termcap.h>
# include <term.h>
# include <fcntl.h>

# define CMD_OTHER 1
# define CMD_ECHO 2
# define CMD_CD 3
# define CMD_PWD 4
# define CMD_EXPORT 5
# define CMD_UNSET 6
# define CMD_ENV 7
# define CMD_EXIT 8

typedef struct s_state
{
	int				process_running;
	int				fd_stdin;
	int				fd_stdout;
	int				fd_stderr;
	int				argc;
	char			**argv;
	struct termios	term;
}					t_state;

typedef struct s_history
{
	int			size;
	char		**content;
	int			current;
}				t_history;

typedef struct s_pipe
{
	int			pipe_to_next;
	int			fd_in;
	int			append_output;
	int			append_err_output;
	char		*file_out;
	char		*err_file_out;
	char		*file_in;
}				t_pipe;

typedef struct s_parse
{
	int				command_id;
	t_list			*argv;
	char			**env;
	t_pipe			pipe_info;
	int				next_parse_fd_in;
	int				num_quote;
	int				q;
	int				wq;
}					t_parse;

//	Logic
void	execute_command_line(t_parse *parse, char ***env);

void	cmd_other(t_parse *parse, char **env);
void	cmd_echo(t_parse *parse);
void	cmd_cd(t_parse *parse, char ***env);
void	cmd_pwd(void);
void	cmd_export(t_parse *parse, char ***env);
void	cmd_unset(t_parse *parse, char ***env);
void	cmd_env(char **env);
void	cmd_exit(t_parse *parse);

void	insert_env(char *key, char *new_env, char ***env);
char	*get_env(char *key, char **env);
char	**arr_realloc(char **arr);
void	sort_arr(char **arr);
int		get_fd_in(t_parse *parse);
int		get_fd_out(t_parse *parse);
int		get_fd_err(t_parse *parse);

void	history_add(t_history *history, char *command_line);

void	sigint_handler(int sig);
void	sigquit_handler(int sig);

void	clear_array(char **arr);
int		is_valid_key(char *key);

void	termcap_up(int *command_nbr, char *command_line, int *pos,
			t_history *history);
void	termcap_down(int *command_nbr, char *command_line, int *pos,
			t_history *history);
void	termcap_backspace(int *pos, char *command_line);
void	termcap_input(char *command_line, int *pos, const char *str);
char	termcap_loop(int *command_nbr, int *pos, char *command_line,
			t_history *history);

void	throw_error(char *argv, char *description, int err);
int		throw_open_error(char *file);

//	Parse

void	ft_skip_space(char **buff);
void	ft_push_text(char **str, t_parse *parse, int chk);

void	parse_line(char *buff, char ***env);
int		ft_walk_str(char *str);
int		ft_check_arg(char *arg, char *buff, int n);
void	ft_init_parse(t_parse *parse, char **env);

void	ft_get_pwd_env(t_parse *parse, int id, char **str);
void	ft_get_echo(t_parse *parse, char **str);
void	ft_get_cd(t_parse *parse, char **str);
void	ft_get_export(t_parse *parse, char **str);
void	ft_get_unset(t_parse *parse, char **str);
void	ft_text(char **str, t_parse *parse, int n);
void	ft_text_q(char **str, t_parse *parse, int n);
void	ft_get_exit(t_parse *parse, char **str);
void	ft_get_other(t_parse *parse, char **str);

char	*ft_for_print(char **str, t_parse *parse, char *ch);
char	*ft_for_print_q(char **str, t_parse *parse, char *ch);
int		ft_strchar_int(const char *str, char *line);
void	ft_fshell(char **tmp, char **buff);
void	ft_push_argv(char *str, t_parse *parse, int n);
char	*ft_convers_dol(t_parse *parse, char **str);

int		ft_get_outfile(char **str, t_parse *parse);
int		ft_get_infile(char **str, t_parse *parse);
int		ft_get_errfile(char **str, t_parse *parse);

char	*ft_dollar(char **str, t_parse *parse);
char	*ft_prequote(char **str, t_parse *parse);
char	*ft_preparse_wquotes(char **str, t_parse *parse);
char	*ft_prewquote(char **str, t_parse *parse);
char	*ft_preescape(char **str);
char	*ft_escape(char **str);

int		ft_check_red(char **str, t_parse *parse, int err);
int		ft_check_sym(char **str, t_parse *parse, int *num_quote, int chk);
void	ft_read_line(char **str, t_parse *parse, int *num_quote);
void	ft_get_arg(char **buff, t_parse *parse);

void	ft_parse_for_other(char **str, char **line, t_parse *parse);
int		ft_parse_for_escape(char **str, char **line);
void	ft_parse_for_doll(char **str, char **line, t_parse *parse);
int		ft_parse_for_quote(char **str, char **line, t_parse *parse);
int		ft_parse_for_wquote(char **str, char **line, t_parse *parse);

#endif
