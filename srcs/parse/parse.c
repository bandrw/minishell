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

	buff = ft_for_print(str, parse, "$\t\n\v\f\r ;");
	ft_push_argv(buff, parse, n);
}

void	ft_read_line(char **str, t_parse *parse, int num_quote)
{
	int check;

	while (**str && **str != ';')
	{
		check = 1;
		while (ft_isspace(**str))
		{
			(*str)++;
			check = 0;
		}
		if (**str == '\'')
			ft_quote(str, parse, check);
		else if (**str == '\"')
			ft_wquote(str, parse, check, ++num_quote);
		else if (**str == '$')
			ft_dollar(str, parse, check);
		else
			ft_text(str, parse, check);
	}
	if (**str == ';')
		(*str)++;
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

void	parse_line(char *line, t_list **parse_list, char **env)
{
	while (*line)
	{
		t_parse *parse;

		parse = (t_parse *)malloc(sizeof(t_parse));
		ft_bzero(parse, sizeof(t_parse));
		parse->env = env;
	//	parse->command_id = CMD_ENV;
	//	parse->pipe_info.pipe_to_next = 1;
	//	ft_lstadd_back(parse_line, ft_lstnew(parse));
	//
	//	parse = (t_parse *)malloc(sizeof(t_parse));
	//	ft_bzero(parse, sizeof(t_parse));
	//	parse->env = env;
	//	parse->command_id = CMD_OTHER;
	//	ft_lstadd_back(&parse->argv, ft_lstnew(ft_strdup("cat")));
	//	ft_lstadd_back(&parse->argv, ft_lstnew(ft_strdup("-e")));
	//	parse->pipe_info.file_out = ft_strdup("out.txt");
	//	ft_lstadd_back(parse_line, ft_lstnew(parse));

		while (ft_isspace(*line))
			line++;
		if (ft_strncmp("echo", line, 4) == 0 && (!line[4]
			|| ft_isspace(line[4])))
			ft_get_echo(parse, &line);
		else if (ft_strncmp("cd", line, 2) == 0 && (!line[2]
			|| ft_isspace(line[2])))
			ft_get_cd(parse, &line);
		else if (ft_strncmp("pwd", line, 3) == 0 && (!line[3]
			|| ft_isspace(line[3])))
			ft_get_pwd_env(parse, CMD_PWD, &line);
		else if (ft_strncmp("export", line, 6) == 0 && (!line[6]
			|| ft_isspace(line[6])))
			ft_get_export(parse, &line);
		else if (ft_strncmp("unset", line, 5) == 0 && (!line[5]
			|| ft_isspace(line[5])))
			ft_get_unset(parse, &line);
		else if (ft_strncmp("env", line, 3) == 0 && (!line[3]
			|| ft_isspace(line[3])))
			ft_get_pwd_env(parse, CMD_ENV, &line);
		else if (ft_strncmp("exit", line, 4) == 0 && (!line[4]
			|| ft_isspace(line[4])))
			ft_get_exit(parse, &line);
		else
			ft_get_other(parse, &line);
		ft_lstadd_back(parse_list, ft_lstnew(parse));
	}
}
