/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:46:49 by pantigon          #+#    #+#             */
/*   Updated: 2021/05/12 20:48:39 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
extern t_state	g_state;

int	ft_parse_for_wquote(char **str, char **line, t_parse *parse)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_prewquote(str, parse);
	if (!tmp)
		return (-1);
	tmp1 = *line;
	*line = ft_strjoin(*line, tmp);
	free(tmp);
	if (tmp1)
		free(tmp1);
	return (1);
}

int	ft_parse_for_quote(char **str, char **line, t_parse *parse)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_prequote(str, parse);
	if (tmp == 0)
		return (-1);
	tmp1 = *line;
	*line = ft_strjoin(*line, tmp);
	free(tmp);
	if (tmp1)
		free(tmp1);
	return (1);
}

void	ft_parse_for_doll(char **str, char **line, t_parse *parse)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_dollar(str, parse);
	if (tmp)
	{
		tmp1 = *line;
		*line = ft_strjoin(*line, tmp);
		free(tmp);
		if (tmp1)
			free(tmp1);
	}
}

void	ft_parse_for_other(char **str, char **line, t_parse *parse)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_for_print(str, parse, "$;\'\"");
	tmp1 = *line;
	*line = ft_strjoin(*line, tmp);
	free(tmp);
	if (tmp1)
		free(tmp1);
}
