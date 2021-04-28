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

	buff = ft_for_print(str, parse);
	ft_push_argv(buff, parse, n);
}

void	ft_read_line(char **str, t_parse *parse)
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
		if (**str == '$')
			ft_dollar(str, parse, check);
		else
			ft_text(str, parse, check);
	}

}

void	ft_get_other(t_parse *parse, char *str)
{
	char **buff;
	parse->command_id = CMD_OTHER;
	buff = ft_split(str, ' ');
	while (*buff)
	{
		ft_lstadd_back(&parse->argv, ft_lstnew(*buff));
		buff++;
	}
}

void	parse_line(char *line, t_parse *parse)
{
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
		ft_get_pwd_env_exit(parse, CMD_PWD);
	else if (ft_strncmp("export", line, 6) == 0 && (!line[6]
		|| ft_isspace(line[6])))
		ft_get_export(parse, &line);
	else if (ft_strncmp("unset", line, 5) == 0 && (!line[5]
		|| ft_isspace(line[5])))
		ft_get_unset(parse, &line);
	else if (ft_strncmp("env", line, 3) == 0 && (!line[3]
		|| ft_isspace(line[3])))
		ft_get_pwd_env_exit(parse, CMD_ENV);
	else if (ft_strncmp("exit", line, 4) == 0 && (!line[4] // todo: exit with argv
		|| ft_isspace(line[4])))
		ft_get_exit(parse, &line);
	else
		ft_get_other(parse, line);
}
