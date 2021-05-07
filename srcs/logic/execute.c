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

extern t_state g_state;

static void	execute_selector(t_parse *parse, char ***env, const int std_copy[3])
{
	g_state.process_running = 1;
	g_state.fd_stdin = std_copy[0];
	g_state.fd_stdout = std_copy[1];
	g_state.fd_stderr = std_copy[2];
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
	g_state.process_running = 0;
}

static void	close_fds(int fd[3], int std_copy[3])
{
	if (fd[0] != 0 && fd[0] >= 0)
	{
		dup2(std_copy[0], 0);
		close(fd[0]);
		close(std_copy[0]);
	}
	if (fd[1] != 1 && fd[1] >= 0)
	{
		dup2(std_copy[1], 1);
		close(fd[1]);
		close(std_copy[1]);
	}
	if (fd[2] != 2 && fd[2] >= 0)
	{
		dup2(std_copy[2], 2);
		close(fd[2]);
		close(std_copy[2]);
	}
}

static int	open_fds(t_parse *parse, int fd[3], int std_copy[3])
{
	std_copy[0] = 0;
	std_copy[1] = 1;
	std_copy[2] = 2;
	fd[0] = get_fd_in(parse);
	if (fd[0] < 0)
	{
		close_fds(fd, std_copy);
		return (1);
	}
	fd[1] = get_fd_out(parse);
	if (fd[1] < 0)
	{
		close_fds(fd, std_copy);
		return (2);
	}
	fd[2] = get_fd_err(parse);
	if (fd[2] < 0)
	{
		close_fds(fd, std_copy);
		return (3);
	}
	return (0);
}

void	execute_command_line(t_parse *parse, char ***env)
{
	int	fd[3];
	int	std_copy[3];

	if (open_fds(parse, fd, std_copy))
		return ;
	if (fd[0] != 0)
	{
		std_copy[0] = dup(0);
		dup2(fd[0], 0);
	}
	if (fd[1] != 1)
	{
		std_copy[1] = dup(1);
		dup2(fd[1], 1);
	}
	if (fd[2] != 2)
	{
		std_copy[2] = dup(2);
		dup2(fd[2], 2);
	}
	execute_selector(parse, env, std_copy);
	close_fds(fd, std_copy);
}
