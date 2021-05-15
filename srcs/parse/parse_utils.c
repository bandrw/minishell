/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 18:33:59 by pantigon          #+#    #+#             */
/*   Updated: 2021/05/15 18:34:02 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_push_text(char **str, t_parse *parse, int chk)
{
	if (**str == '\'')
	{
		(*str)++;
		parse->q += 1;
	}
	else if (**str == '\"')
	{
		(*str)++;
		parse->wq += 1;
	}
	if (parse->q % 2 != 0 || parse->wq % 2 != 0)
		ft_text_q(str, parse, chk);
	else
		ft_text(str, parse, chk);
}

void	ft_convers_add(char **str, char **line, t_parse *parse)
{
	if (**str == '$')
		ft_parse_for_doll(str, line, parse);
	else
		ft_parse_for_other(str, line);
}

char	*ft_convers_dol(t_parse *parse, char **str)
{
	char	*line;

	line = 0;
	ft_skip_space(str);
	while (**str && ft_strchr(";", **str) == 0)
	{
		if (**str == '\'')
		{
			if (ft_parse_for_quote(str, &line, parse) == -1)
				return (0);
		}
		else if (**str == '\"')
		{
			if (ft_parse_for_wquote(str, &line, parse) == -1)
				return (0);
		}
		else if (**str == '\\')
		{
			if (ft_parse_for_escape(str, &line) == -1)
				return (0);
		}
		else
			ft_convers_add(str, &line, parse);
	}
	return (line);
}
