/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfriese <kfriese@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:04:36 by kfriese           #+#    #+#             */
/*   Updated: 2021/04/18 17:04:39 by kfriese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_selector(t_parse *parse, char ***env)
{
	if (parse->command_id == CMD_OTHER)
		cmd_other(parse, *env);
	else if (parse->command_id == CMD_ECHO)
		cmd_echo(parse);
	else if (parse->command_id == CMD_CD)
		cmd_cd(parse, env);
	else if (parse->command_id == CMD_PWD)
		cmd_pwd();
	else if (parse->command_id == CMD_EXPORT)
		cmd_export(parse, env);
	else if (parse->command_id == CMD_UNSET)
		cmd_unset(parse, env);
	else if (parse->command_id == CMD_ENV)
		cmd_env(*env);
	else if (parse->command_id == CMD_EXIT)
		cmd_exit(parse);
}

void	execute_command_line(t_parse *parse, char ***env)
{
	int	fd_in;
	int	fd_out;
	int	fd_err;
	int	stdin_copy;
	int	stdout_copy;
	int	stderr_copy;

	fd_in = get_fd_in(parse);
	fd_out = get_fd_out(parse);
	fd_err = get_fd_err(parse);
	if (fd_in != 0)
	{
		stdin_copy = dup(0);
		dup2(fd_in, 0);
	}
	if (fd_out != 1)
	{
		stdout_copy = dup(1);
		dup2(fd_out, 1);
	}
	if (fd_err != 2)
	{
		stderr_copy = dup(2);
		dup2(fd_err, 2);
	}
	execute_selector(parse, env);
	if (fd_in != 0)
	{
		dup2(stdin_copy, 0);
		close(fd_in);
		close(stdin_copy);
	}
	if (fd_out != 1)
	{
		dup2(stdout_copy, 1);
		close(fd_out);
		close(stdout_copy);
	}
	if (fd_err != 2)
	{
		dup2(stderr_copy, 2);
		close(fd_err);
		close(stderr_copy);
	}
}
