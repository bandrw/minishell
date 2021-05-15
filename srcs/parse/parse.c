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

void	ft_skip_brk(char **line, t_parse *parse)
{
	if (**line == ';')
		(*line)++;
}

void	ft_skip_space(char **buff, t_parse *parse)
{
	while (ft_isspace(**buff))
		(*buff)++;
}

int 	ft_loop_for_parse(char *line, char ***env)
{
	char	*line_start;
	char	*buff;
	char	*tmp;
	t_parse	parse;

	line = ft_strdup(line);
	ft_bzero(&parse, sizeof(parse));
	while (*line)
	{
		line_start = line;
		ft_skip_brk(&line, &parse);
		ft_init_parse(&parse, *env);
		buff = ft_convers_dol(&parse, &line);
		tmp = buff;
		if (!buff)
			return (-1);
		ft_skip_space(&buff, &parse);
		ft_get_arg(&buff, &parse);
		execute_command_line(&parse, env);
		line = ft_strjoin(buff, line);
		free(line_start);
		free(tmp);
	}
	free(line);
	return (1);
}

void	parse_line(char *line, char ***env)
{
	while (ft_isspace(*line))
		line++;
	if (ft_walk_str(line) == -1)
	{
		ft_putendl_fd("syntax error near unexpected token `;'", 2);
		return ;
	}
	ft_loop_for_parse(line, env);
}

//void	parse_line(char *line, char ***env)
//{
//	int	check;
//
//	while (ft_isspace(*line))
//		line++;
////	if (*line == ';')
////	{
////		ft_putendl_fd("syntax error near unexpected token `;'", 2);
////		return ;
////	}
//	check = ft_loop_for_parse(line, env);
//	if (check == -2)
//	{
//		ft_putendl_fd("syntax error near unexpected token `;'", 2);
//		return ;
//	}
//}

//int	ft_skip_brk(char **line, t_parse *parse)
//{
//	if (**line == ';')
//	{
//		if (parse->command_id == 0)
//		{
//			ft_putendl_fd("syntax error near unexpected token `;'", 2);
//			return (-1);
//		}
//		(*line)++;
//	}
//	return (1);
//}
//
//int	ft_skip_space(char **buff,  t_parse *parse)
//{
//	while (ft_isspace(**buff))
//		(*buff)++;
//	if (**buff == ';' && parse->command_id == 0)
//	{
//		ft_putendl_fd("syntax error near unexpected token `;'", 2);
//		return (-1);
//	}
//	return (1);
//}
//
//int 	ft_loop_for_parse(char *line, char ***env)
//{
//	char	*line_start;
//	char	*buff;
//	char	*tmp;
//	t_parse	parse;
//
//	line = ft_strdup(line);
//	ft_bzero(&parse, sizeof(parse));
//	while (*line)
//	{
//		line_start = line;
//		if (ft_skip_brk(&line, &parse) == -1)
//			return (-1);
//		ft_init_parse(&parse, *env);
//		buff = ft_convers_dol(&parse, &line);
//		tmp = buff;
//		if (!buff)
//			return (-1);
//		if (ft_skip_space(&buff, &parse) == -1)
//			return (-1);
//		ft_get_arg(&buff, &parse);
//		execute_command_line(&parse, env);
//		line = ft_strjoin(buff, line);
//		free(line_start);
//		free(tmp);
//	}
//	free(line);
//	return (1);
//}
//
//void	parse_line(char *line, char ***env)
//{
//	while (ft_isspace(*line))
//		line++;
////	if (*line == ';')
////	{
////		ft_putendl_fd("syntax error near unexpected token `;'", 2);
////		return ;
////	}
//	if (ft_loop_for_parse(line, env) == -1)
//		return ;
//}
