/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <pantigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:00:05 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/25 17:11:27 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_red(char **str, t_parse *parse, int err)
{
	if (err == 0)
	{
		(*str)++;
		if (**str == '>')
		{
			(*str)++;
			parse->pipe_info.append_output = 1;
		}
		return (ft_get_outfile(str, parse));
	}
	else
	{
		(*str) += 2;
		if (**str == '>')
		{
			(*str)++;
			parse->pipe_info.append_err_output = 1;
		}
		return (ft_get_errfile(str, parse));
	}
}

int	ft_check_sym(char **str, t_parse *parse, int *num_quote, int chk)
{
	if (**str == '\'')
		ft_quote(str, parse, chk);
	else if (**str == '\"')
		ft_wquote(str, parse, chk, num_quote);
	else if (**str == '|')
	{
		parse->pipe_info.pipe_to_next = 1;
		(*str)++;
		return (-1);
	}
	else if (**str == '>')
	{
		if (ft_check_red(str, parse, 0) == -1)
			return (-1);
	}
	else if (**str == '2' && (*(*str + 1)) == '>')
	{
		if (ft_check_red(str, parse, 1) == -1)
			return (-1);
	}
	else
		ft_text(str, parse, chk);
	return (0);
}

void	ft_read_line(char **str, t_parse *parse, int *num_quote)
{
	int	check;

	while (**str)
	{
		check = 1;
		while (ft_isspace(**str))
		{
			(*str)++;
			check = 0;
		}
		if (!**str)
			return ;
		if (**str == ';')
		{
			(*str)++;
			return ;
		}
		if (ft_check_sym(str, parse, num_quote, check) == -1)
			return ;
	}
}

void	ft_get_arg(char **buff, t_parse *parse)
{
	if (ft_check_arg("echo", *buff, 4) == 1)
		ft_get_echo(parse, buff);
	else if (ft_check_arg("cd", *buff, 2) == 1)
		ft_get_cd(parse, buff);
	else if (ft_check_arg("pwd", *buff, 3) == 1)
		ft_get_pwd_env(parse, CMD_PWD, buff);
	else if (ft_check_arg("export", *buff, 6) == 1)
		ft_get_export(parse, buff);
	else if (ft_check_arg("unset", *buff, 5) == 1)
		ft_get_unset(parse, buff);
	else if (ft_check_arg("env", *buff, 3) == 1)
		ft_get_pwd_env(parse, CMD_ENV, buff);
	else if (ft_check_arg("exit", *buff, 4) == 1)
		ft_get_exit(parse, buff);
	else if (*buff)
		ft_get_other(parse, buff);
}

//void	parse_line(char *line, int argc, char **argv, char ***env)
//{
//	char	*buff;
//	t_parse	parse;
//	//int	fd_in;
//
//	buff = 0;
//	ft_bzero(&parse, sizeof(parse));
//	while (*line)
//	{
//		if (*line == ';')
//			line++;
//		//fd_in = 0;
//		ft_init_parse(&parse, *env);
////		if (parse.next_parse_fd_in)
////			fd_in = parse.next_parse_fd_in;
////		ft_bzero(&parse, sizeof(parse));
////		parse.env = *env;
////		parse.pipe_info.fd_in = fd_in;
//		buff = ft_convers_dol(&parse, &line, argc, argv);
//		if (!buff)
//			return ;
//		while (ft_isspace(*buff))
//			buff++;
//		ft_get_arg(&buff, &parse);
//		execute_command_line(&parse, env);
//		if (*buff)
//			line = ft_strjoin(buff, line);
//	}
//}

static t_parse	*tmp_parse_dup(t_parse *src)
{
	t_parse	*dup;

	dup = (t_parse*)malloc(sizeof(t_parse));
	dup->command_id = src->command_id;
	dup->argv = src->argv;
	dup->next_parse_fd_in = src->next_parse_fd_in;
	dup->env = src->env;
	dup->pipe_info.err_file_out = src->pipe_info.err_file_out;
	dup->pipe_info.fd_in = src->pipe_info.fd_in;
	dup->pipe_info.file_in = src->pipe_info.file_in;
	dup->pipe_info.file_out = src->pipe_info.file_out;
	dup->pipe_info.pipe_to_next = src->pipe_info.pipe_to_next;
	dup->pipe_info.append_err_output = src->pipe_info.append_err_output;
	dup->pipe_info.append_output = src->pipe_info.append_output;
	return (dup);
}

// Version for CTests
t_list	*parse_line(char *line, int argc, char **argv, char ***env)
{
	t_list	*list;
	t_parse	parse;
	char	*buff;

	list = 0;
	buff = 0;
	ft_bzero(&parse, sizeof(parse));
	while (*line)
	{
		if (*line == ';')
			line++;
		ft_init_parse(&parse, *env);
		buff = ft_convers_dol(&parse, &line, argc, argv);
		if (!buff)
			return (list);
		while (ft_isspace(*buff))
			buff++;
		ft_get_arg(&buff, &parse);
		ft_lstadd_back(&list, ft_lstnew(tmp_parse_dup(&parse)));
		execute_command_line(&parse, env);
		if (*buff)
			line = ft_strjoin(buff, line);
	}
	return (list);
}
