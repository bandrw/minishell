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

void	ft_text(char **str, t_parse *parse, int n)
{
	char	*buff;

	buff = ft_for_print(str, parse, "$\t\n\v\f\r ;\'\"");
	ft_push_argv(buff, parse, n);
}

void	ft_read_line(char **str, t_parse *parse, int num_quote)
{
	int check;

	while (**str)
	{
		check = 1;
		while (ft_isspace(**str))
		{
			(*str)++;
			check = 0;
		}
		if (**str == ';')
		{
			(*str)++;
			return ;
		}
		if (**str == '\'')
			ft_quote(str, parse, check);
		else if (**str == '\"')
			ft_wquote(str, parse, check, ++num_quote);
//		else if (**str == '$')
//			ft_dollar(str, parse, check);
		else if (**str)
			ft_text(str, parse, check);
	}
}

void	ft_get_other(t_parse *parse, char **str)
{
	//char **buff;

	parse->command_id = CMD_OTHER;
	ft_read_line(str, parse, 0);
//	buff = ft_split_str(str, "t\n\v\f\r ");
//	while (*buff)
//	{
//		ft_lstadd_back(&parse->argv, ft_lstnew(*buff));
//		buff++;
//	}
//	parse->file_out = ft_strdup("out.txt"); // (logic handled)
//	parse->file_in = ft_strdup("../srcs/main.c"); // (logic handled)
}

void	parse_line(char *line, char ***env)
{
	int		next_parse_fd_in;
	char	*buff;
	t_parse	parse;

	next_parse_fd_in = 0;
	//buff = 0;
	while (*line)
	{
//		while (ft_isspace(*line))
//			line++;
		if (*line == ';')
			line++;
		if (parse.next_parse_fd_in)
			next_parse_fd_in = parse.next_parse_fd_in;
		ft_bzero(&parse, sizeof(parse));
		parse.env = *env;
		parse.next_parse_fd_in = next_parse_fd_in;
		buff = ft_convers_dol(&parse, &line);
		while (*buff && ft_isspace(*buff))
			buff++;
		if (ft_strncmp("echo", buff, 4) == 0 && (!buff[4]
		|| ft_isspace(buff[4])))
			ft_get_echo(&parse, &buff);
		else if (ft_strncmp("cd", buff, 2) == 0 && (!buff[2]
		|| ft_isspace(buff[2])))
			ft_get_cd(&parse, &buff);
		else if (ft_strncmp("pwd", buff, 3) == 0 && (!buff[3]
		|| ft_isspace(buff[3])))
			ft_get_pwd_env(&parse, CMD_PWD, &buff);
		else if (ft_strncmp("export", buff, 6) == 0 && (!buff[6]
		|| ft_isspace(buff[6])))
			ft_get_export(&parse, &buff);
		else if (ft_strncmp("unset", buff, 5) == 0 && (!buff[5]
		|| ft_isspace(buff[5])))
			ft_get_unset(&parse, &buff);
		else if (ft_strncmp("env", buff, 3) == 0 && (!buff[3]
		|| ft_isspace(buff[3])))
			ft_get_pwd_env(&parse, CMD_ENV, &buff);
		else if (ft_strncmp("exit", buff, 4) == 0 && (!buff[4]
		|| ft_isspace(buff[4])))
			ft_get_exit(&parse, &buff);
		else if (*buff)
			ft_get_other(&parse, &buff);
		execute_command_line(&parse, env);
	}
}
