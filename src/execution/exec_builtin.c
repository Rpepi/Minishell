/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:39:56 by pepi              #+#    #+#             */
/*   Updated: 2024/09/25 13:40:55 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	execute_builtin_pipeline(t_env *env, t_cmd *cmd, int index)
{
	pid_t	pid;

	ignore_sigint();
	pid = fork();
	if (pid < 0)
	{
		perror("minishell: fork");
		quit_program(env);
	}
	if (pid == 0)
	{
		setup_child_signals();
		close_unused_pipes(env, index);
		exec_built_in(env, cmd);
		exit(env->last_exit_status);
	}
	else
	{
		cmd->pid = pid;
		wait_for_process(env, cmd->pid);
		setup_shell_signals();
	}
}

void	execute_builtin(t_env *env, t_cmd *cmd, int is_pipeline, int index)
{
	if (is_pipeline)
		execute_builtin_pipeline(env, cmd, index);
	else
		env->last_exit_status = exec_built_in(env, cmd);
}
