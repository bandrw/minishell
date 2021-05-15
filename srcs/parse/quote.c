/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:47:13 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/28 16:47:15 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_quote(char **line, char *ch)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, ch);
	free(tmp);
}

char	*ft_prequote(char **str, t_parse *parse)
{
	char	*buff;
	char	*line;

	line = ft_for_print_q(str, parse, "\'");
	if (**str != '\'')
	{
		ft_putendl_fd("Error: need second quote", 2);
		parse->command_id = -1;
		return (0);
	}
	else
	{
		(*str) += 1;
		ft_add_quote(&line, "\'");
		return (line);
	}
}

char	*ft_preparse_wquotes(char **str, t_parse *parse)
{
	char	*buff;
	char	*tmp;

	buff = 0;
	while (**str && **str != '\"')
	{
		if (**str == '$')
			tmp = ft_dollar(str, parse);
		else if (**str == '\\')
		{
			if (ft_strchr("$\\", (*(*str + 1))) != 0)
				tmp = ft_escape(str);
			else
				tmp = ft_preescape(str);
		}
		else
			tmp = ft_for_print(str, parse, "$\"\\");
		ft_fshell(&tmp, &buff);
	}
	return (buff);
}

int	ft_check_num_quote(char ch, t_parse *parse)
{
	if (ch != '\"')
	{
		ft_putendl_fd("Error: need second quote", 2);
		parse->command_id = -1;
		return (-1);
	}
	return (1);
}

char	*ft_prewquote(char **str, t_parse *parse)
{
	char	*buff;
	char	*tmp;
	char	*tmp1;

	parse->num_quote++;
	tmp = 0;
	if (parse->num_quote % 2 != 0)
	{
		buff = ft_for_print_q(str, parse, "\\$\"");
		while (**str && **str != '\"')
			tmp = ft_preparse_wquotes(str, parse);
		if (ft_check_num_quote(**str, parse) == -1)
			return (0);
		tmp1 = buff;
		buff = ft_strjoin(buff, tmp);
		free(tmp);
		if (tmp1)
			free(tmp1);
		parse->num_quote++;
		ft_add_quote(&buff, "\"");
		(*str)++;
		return (buff);
	}
	return (0);
}
