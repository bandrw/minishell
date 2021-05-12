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
	if (**str == '|')
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
	else if (**str == '<')
	{
		if (ft_get_infile(str, parse) == -1)
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

int 	ft_loop_for_parse(char *line, int argc, char **argv, char ***env)
{
	char	*line_start;
	char	*buff;
	char	*tmp;
	t_parse	parse;

	ft_bzero(&parse, sizeof(parse));
	while (*line)
	{
		line_start = line;
		if (*line == ';')
			line++;
		ft_init_parse(&parse, *env);
		buff = ft_convers_dol(&parse, &line, argc, argv);
		tmp = buff;
		if (!buff)
			return (-1);
		while (ft_isspace(*buff))
			buff++;
		ft_get_arg(&buff, &parse);
		execute_command_line(&parse, env);
		line = ft_strjoin(buff, line);
		free(line_start);
		free(tmp);
	}
	free(line);
	return (1);
}

void	parse_line(char *line, int argc, char **argv, char ***env)
{
	char	*line_start;
	char	*buff;
	char	*tmp;
//	t_parse	parse;

	buff = 0;
	line = ft_strdup(line);
	line_start = line;
//	ft_bzero(&parse, sizeof(parse));
	tmp = 0;
	while (ft_isspace(*line))
		line++;
	if (*line == ';')
	{
		ft_putendl_fd("syntax error near unexpected token `;'", 2);
		free(line_start);
		return ;
	}
	if (ft_loop_for_parse(line, argc, argv, env) == -1)
		return ;
//	while (*line)
//	{
//		line_start = line;
//		if (*line == ';')
//			line++;
//		ft_init_parse(&parse, *env);
//		buff = ft_convers_dol(&parse, &line, argc, argv);
//		tmp = buff;
//		if (!buff)
//			return ;
//		while (ft_isspace(*buff))
//			buff++;
//		ft_get_arg(&buff, &parse);
//		execute_command_line(&parse, env);
//		line = ft_strjoin(buff, line);
//		free(line_start);
//		free(tmp);
//	}
//	free(line);
}
