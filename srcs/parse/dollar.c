/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pantigon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:35:32 by pantigon          #+#    #+#             */
/*   Updated: 2021/04/27 19:35:35 by pantigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prequote(char **str, t_parse *parse)
{
	char	*buff;

	(*str) += 1;
	buff = ft_for_print(str, parse, "\'");
	if (**str != '\'')
	{
		ft_putendl_fd("Error: need second quote", 2);
		parse->command_id = -1;
		return (0);
	}
	else
	{
		(*str) += 1;
		return (buff);
	}
}

char	*ft_preparse_wquotes(char **str, t_parse *parse, int ac, char **av)
{
	char	*buff;
	char	*tmp;
	char	*tmp1;

	buff = 0;
	while (**str && **str != '\"')
	{
		if (**str == '$')
			tmp = ft_dollar(str, parse, ac, av);
		else
			tmp = ft_for_print(str, parse, "$\"");
		if (tmp)
		{
			tmp1 = buff;
			buff = ft_strjoin(buff, tmp);
			free(tmp);
			if (tmp1)
				free(tmp1);
		}
	}
	return (buff);
}

char	*ft_prewquote(char **str, t_parse *parse, int *n_q , int ac, char **av)
{
	char	*buff;
	char	*tmp;
	char	*tmp1;

	(*str) += 1;
	*n_q += 1;
	tmp = 0;
	if (*n_q % 2 != 0)
	{
		buff = ft_for_print(str, parse, "$\"");
		while (**str && **str != '\"')
			tmp = ft_preparse_wquotes(str, parse, ac, av);
		if (**str != '\"')
		{
			ft_putendl_fd("Error", 2);
			parse->command_id = -1;
			return (0);
		}
		tmp1 = buff;
		buff = ft_strjoin(buff, tmp);
		free(tmp);
		if (tmp1)
			free(tmp1);
		(*str)++;
		return (buff);
	}
	return (0);
}

char	*ft_convers_dol(t_parse *parse, char **str, int ac, char **av)
{
	char	*line;
	char	*tmp;
	char	*tmp1;
	int		num_quote;

	line = 0;
	num_quote = 0;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == ';')
	{
		ft_putendl_fd("syntax error near unexpected token `;'", 2);
		return (0);
	}
	while (**str && ft_strchr(";", **str) == 0)
	{
		if (**str == '\'')
		{
			tmp = ft_prequote(str, parse);
			if (tmp == 0)
				return (0);
			tmp1 = line;
			line = ft_strjoin(line, tmp);
			free(tmp);
			if (tmp1)
				free(tmp1);
		}
		else if (**str == '"')
		{
			tmp = ft_prewquote(str, parse, &num_quote, ac, av);
			if (!tmp)
				return (0);
			tmp1 = line;
			line = ft_strjoin(line, tmp);
			free(tmp);
			if (tmp1)
				free(tmp1);
		}
		else if (**str == '$')
		{
			tmp = ft_dollar(str, parse, ac, av);
			if (tmp)
			{
				tmp1 = line;
				line = ft_strjoin(line, tmp);
				free(tmp);
				if (tmp1)
					free(tmp1);
			}
		}
		else
		{
			tmp = ft_for_print(str, parse, "$;\'\"");
			tmp1 = line;
			line = ft_strjoin(line, tmp);
			free(tmp);
			if (tmp1)
				free(tmp1);
		}
	}
	return (line);
}

char	*ft_get_argv(char **str, t_parse *parse, int argc, char **argv)
{
	char	i;
	char	*env;
	int		j;

	i = '0';
	j = 0;
	while (j <= 9)
	{
		if (i == **str && j < argc)
		{
			env = ft_strdup(argv[j]);
			(*str) += 1;
			return (env);
		}
		i++;
		j++;
	}
	(*str) += 1;
	return (0);
}

int 	ft_strchar_isalnum(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		if (ft_isalnum(line[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_for_print_isalnum(char **str, t_parse *parse)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = ft_strchar_isalnum(*str) + 1;
	tmp = (char *) malloc(sizeof(char) * (i));
	ft_strlcpy(tmp, *str, i);
	(*str) += i - 1;
	return (tmp);
}

char	*ft_dollar(char **str, t_parse *parse, int argc, char **argv)
{
	char	*buff;
	char	*env;

	(*str) += 1;
	if (ft_isdigit(**str) != 0)
		return (ft_get_argv(str, parse, argc, argv));
	if (**str == '?')
	{
		env = ft_itoa(errno);
		(*str) += 1;
		return (env);
	}
	buff = ft_for_print_isalnum(str, parse);
	env = ft_strdup(get_env(buff, parse->env));
	free(buff);
	return (env);
}
