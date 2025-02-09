/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:39:14 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/26 09:42:55 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	update_exit_status(t_env *env, int status)
{
	if (WIFEXITED(status))
		env->last_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		env->last_exit_status = 128 + WTERMSIG(status);
}

void	wait_for_process(t_env *env, pid_t pid)
{
	int		status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		env->last_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		env->last_exit_status = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
		else if (WTERMSIG(status) == SIGQUIT)
			write(STDOUT_FILENO, "Quit: 3\n", 8);
	}
}

void	wait_all_children(t_env *env)
{
	int		status;
	pid_t	pid;

	pid = waitpid(-1, &status, 0);
	while (pid > 0)
	{
		if (WIFEXITED(status))
			env->last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			env->last_exit_status = 128 + WTERMSIG(status);
			if (WTERMSIG(status) == SIGINT)
				ft_putstr_fd("\n", STDOUT_FILENO);
			else if (WTERMSIG(status) == SIGQUIT)
				ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
		}
		pid = waitpid(-1, &status, 0);
	}
}

static void	update_cmd_status(t_env *env, t_cmd *cmd, int status)
{
	update_exit_status(env, status);
	cmd->pid = 0;
}

void	wait_for_cmd(t_env *env, t_cmd *cmd)
{
	int		status;
	pid_t	result;

	if (cmd->pid > 0)
	{
		result = waitpid(cmd->pid, &status, WNOHANG);
		if (result > 0)
			update_cmd_status(env, cmd, status);
	}
}
