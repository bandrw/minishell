/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:19:40 by pantigon          #+#    #+#             */
/*   Updated: 2021/05/05 18:19:42 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_text_q(char **str, t_parse *parse, int n)
{
	char	*buff;

	if (**str == '\\' && parse->wq % 2 != 0 && (*(*str + 1)) == '"')
		buff = ft_escape(str);
	else if (**str == '\\' && parse->wq % 2 != 0)
		buff = ft_preescape(str);
	else if (parse->wq % 2 != 0)
		buff = ft_for_print(str, "\"\'\\");
	else if (parse->q % 2 != 0)
		buff = ft_for_print(str, "\'");
	else
		buff = ft_for_print(str, "\"\'");
	ft_push_argv(buff, parse, n);
}

void	ft_text(char **str, t_parse *parse, int n)
{
	char	*buff;

	if (**str == '\\')
		buff = ft_escape(str);
	else
		buff = ft_for_print(str, " ;|<>\t\n\v\f\r\\\"\'");
	ft_push_argv(buff, parse, n);
}

void	ft_get_other(t_parse *parse, char **str)
{
	int	quote;

	quote = 0;
	parse->command_id = CMD_OTHER;
	ft_read_line(str, parse);
}
