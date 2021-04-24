/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:46:54 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/24 18:46:55 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	if (sig != SIGINT)
		return ;
	ft_putstr("\b\b  \b\b\nminishell$ ");
}

void	sigquit_handler(int sig)
{
	if (sig != SIGQUIT)
		return ;
	ft_putstr("\b\b  \b\b");
//	ft_putstr("\nminishell$ ");
}

