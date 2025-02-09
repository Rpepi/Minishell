/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.C                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:26:25 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/26 09:41:11 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	exec_built_in(t_env *env, t_cmd *cmd)
{
	int	result;

	if (ft_same(cmd->content, "pwd"))
		result = exec_pwd();
	else if (ft_same(cmd->content, "cd"))
		result = exec_cd(env, cmd);
	else if (ft_same(cmd->content, "echo"))
		result = exec_echo(cmd);
	else if (ft_same(cmd->content, "export"))
		result = exec_export(env, cmd);
	else if (ft_same(cmd->content, "env"))
		result = exec_env(env, cmd);
	else if (ft_same(cmd->content, "exit"))
		result = exec_exit(env, cmd);
	else if (ft_same(cmd->content, "unset"))
		result = exec_unset(env, cmd);
	else
	{
		write(STDERR_FILENO, "builtin not handled\n", 21);
		result = 1;
	}
	env->last_exit_status = result;
	return (result);
}

void	exec_bin_cmd(t_env *env, t_cmd *cmd, int index)
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
		execve(cmd->bin, cmd->args, env->env_variable);
		perror("minishell: execve");
		exit(EXIT_FAILURE);
	}
	cmd->pid = pid;
}
