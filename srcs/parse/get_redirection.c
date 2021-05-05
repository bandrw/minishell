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

void	ft_get_infile(char **str, t_parse *parse)
{
	char	*file;

	while (**str && ft_isspace(**str))
		(*str)++;
	file = ft_for_print(str, parse, " ;\t\n\v\f\r");
	parse->pipe_info.file_in = file;
}