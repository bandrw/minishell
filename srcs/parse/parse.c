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

void	ft_text(char **str, t_parse *parse, int *ac)
{
	char	*buff;

	buff = ft_for_print(str, parse, ac);
	ft_push_argv(buff, parse, ac);
}

void	ft_read_line(char **str, t_parse *parse)
{
	int	ac;

	ac = 0;
	while (**str)
	{
		while (ft_isspace(**str))
			(*str)++;
		if (**str == '$')
			ft_dollar(str, parse, &ac);
		else
			ft_text(str, parse, &ac);
	}

}

void	ft_get_other(t_parse *parse, char *str)
{
	parse->command_id = CMD_OTHER;
	//parse->argv = ft_split(str, ' ');
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
	else if (ft_strncmp("pwd", line, 4) == 0)
		ft_get_pwd_env(parse, 3);
	else if (ft_strncmp("export", line, 6) == 0 && (!line[6]
		|| ft_isspace(line[6])))
		ft_get_export(parse, &line);
//	else if (ft_strncmp("unset", line, 5) == 0 && (!line[5]
//		|| ft_isspace(line[5])))
//		ft_get_unset(parse, line);
	else if (ft_strncmp("env", line, 4) == 0)
		ft_get_pwd_env(parse, 6);
//	else if (ft_strncmp("exit", line, 4) == 0 && (!line[4]
//		|| ft_isspace(line[4])))
//		ft_get_exit(parse, line);
	else
		ft_get_other(parse, line);
}
