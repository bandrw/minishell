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

int	ft_get_errfile(char **str, t_parse *parse)
{
	char	*file;
	int		fd;

	while (**str && ft_isspace(**str))
		(*str)++;
	file = ft_for_print(str, parse, " ;<>|\t\n\v\f\r");
	parse->pipe_info.err_file_out = file;
	fd = open(parse->pipe_info.file_out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	close(fd);
	if (!**str || **str == ';')
		return (-1);
	return (1);
}

int	ft_get_infile(char **str, t_parse *parse)
{
	char	*file;
	int		fd;

	(*str)++;
	while (**str && ft_isspace(**str))
			(*str)++;
	file = ft_for_print(str, parse, " ;|<>\t\n\v\f\r");
	parse->pipe_info.file_in = file;
	if (!**str || **str == ';')
		return (-1);
	return (1);
}

//int	ft_get_infile(char **str, t_parse *parse)
//{
//	char	*file;
//	int		fd;
//
//	(*str)++;
//	while (**str && **str != ';' && **str != '>' && **str != '<' && **str != '|')
//	{
//		while (**str && ft_isspace(**str))
//			(*str)++;
//		if (**str && **str == '2' && (*(*str + 1)) == '>')
//			ft_check_red(str, parse, 1);
//		file = ft_for_print(str, parse, " ;|<>\t\n\v\f\r");
//		fd = open(file, O_RDONLY);
//		if (fd < 0)
//			return (throw_open_error(file));
//		close(fd);
//		parse->pipe_info.file_in = ft_strdup(file);
//	}
//	if (!**str || **str == ';')
//		return (-1);
//	return (1);
//}

int	ft_get_outfile(char **str, t_parse *parse)
{
	char	*file;
	int		fd;

	while (**str && ft_isspace(**str))
		(*str)++;
	file = ft_for_print(str, parse, " ;|<>\t\n\v\f\r");
	parse->pipe_info.file_out = file;
	fd = open(parse->pipe_info.file_out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	close(fd);
	if (!**str || **str == ';')
		return (-1);
	return (1);
}
