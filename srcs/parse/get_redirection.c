/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:18:30 by pantigon          #+#    #+#             */
/*   Updated: 2021/05/05 16:18:32 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_errfile(char **str, t_parse *parse)
{
	char	*file;

	while (**str && ft_isspace(**str))
		(*str)++;
	file = ft_for_print(str, parse, " ;\t\n\v\f\r");
	parse->pipe_info.err_file_out = ft_strdup(file);
	while (**str && ft_isspace(**str))
		(*str)++;
	if (**str && **str != ';')
	{
		ft_putendl_fd("no such file in directory", 2);
		exit(0);
	}
}

void	ft_get_infile(char **str, t_parse *parse)
{
	char	*file;

	(*str)++;
	while (**str && ft_isspace(**str))
		(*str)++;
	file = ft_for_print(str, parse, " ;\t\n\v\f\r");
	parse->pipe_info.file_in = ft_strdup(file);
	while (**str && ft_isspace(**str))
		(*str)++;
	if (**str && **str == '2' && (*(*str + 1)) == '>')
		ft_check_red(str, parse, 1);
	else if (**str && **str != ';')
	{
		ft_putendl_fd("no such file in directory", 2);
		exit(0);
	}
}

void	ft_get_outfile(char **str, t_parse *parse)
{
	char	*file;

	while (**str && ft_isspace(**str))
		(*str)++;
	file = ft_for_print(str, parse, " ;\t\n\v\f\r");
	parse->pipe_info.file_out = ft_strdup(file);
	while (**str && ft_isspace(**str))
		(*str)++;
	if (**str && **str != ';')
	{
		ft_putendl_fd("no such file in directory", 2);
		exit(0);
	}
}
