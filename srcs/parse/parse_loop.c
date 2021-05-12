/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:24:33 by pantigon          #+#    #+#             */
/*   Updated: 2021/05/12 20:26:45 by pantigon         ###   ########.fr       */
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
