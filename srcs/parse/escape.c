/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:51:35 by pantigon          #+#    #+#             */
/*   Updated: 2021/05/15 16:51:37 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_escape(char **str)
{
	char	tmp[2];

	(*str)++;
	tmp[0] = **str;
	(*str)++;
	tmp[1] = '\0';
	return (ft_strdup(tmp));
}

char	*ft_preescape(char **str)
{
	char	tmp[3];

	tmp[0] = **str;
	(*str)++;
	tmp[1] = **str;
	(*str)++;
	tmp[2] = '\0';
	return (ft_strdup(tmp));
}

char	*ft_preescape_quote(char **str)
{
	char	tmp[4];

	tmp[0] = **str;
	tmp[1] = **str;
	(*str)++;
	tmp[2] = **str;
	(*str)++;
	tmp[3] = '\0';
	return (ft_strdup(tmp));
}

int	ft_parse_for_escape_quote(char **str, char **line)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_preescape_quote(str);
	if (tmp == 0)
		return (-1);
	tmp1 = *line;
	*line = ft_strjoin(*line, tmp);
	free(tmp);
	if (tmp1)
		free(tmp1);
	return (1);
}

int	ft_parse_for_escape(char **str, char **line)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_preescape(str);
	if (tmp == 0)
		return (-1);
	tmp1 = *line;
	*line = ft_strjoin(*line, tmp);
	free(tmp);
	if (tmp1)
		free(tmp1);
	return (1);
}
