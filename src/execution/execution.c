/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:27:57 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/07 11:14:05 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	execute_external(t_env *env, t_cmd *cmd, int index)
{
	cmd->bin = get_bin(cmd, env);
	if (!cmd->bin)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->content, 2);
		ft_putstr_fd(": command not found \n", 2);
		return ;
	}
	cmd->args = get_next_args_in_array(cmd);
	if (!cmd->args)
		return ;
	exec_bin_cmd(env, cmd, index);
}

void	execute_cmd(t_env *env, t_token *token, int index)
{
	t_cmd	*cmd;
	int		fd_in;
	int		fd_out;
	int		is_pipeline;

	cmd = get_class(token);
	fd_in = dup(STDIN_FILENO);
	fd_out = dup(STDOUT_FILENO);
	if (!change_fd_pipes(env, token, index))
	{
		env->last_exit_status = 1;
		return ;
	}
	is_pipeline = is_part_of_pipeline(token);
	if (is_built_in(cmd->content))
		execute_builtin(env, cmd, is_pipeline, index);
	else
		execute_external(env, cmd, index);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
}

static void	prepare_execution(t_env *env)
{
	env->nb_cmd = get_nb_cmds(env->first_token);
	env->pipes = init_pipes(env, env->nb_cmd);
	if (env->nb_cmd <= 0)
	{
		if (handle_only_redir(env->first_token, env) != 0)
		{
			ft_putstr_fd("Error: opening files for redirection\n", 2);
			env->last_exit_status = 1;
		}
	}
}

void	execution(t_env *env)
{
	t_token	*token;
	int		i;

	prepare_execution(env);
	if (env->nb_cmd <= 0)
		return ;
	i = 0;
	token = env->first_token;
	while (token)
	{
		if (env->env_variable)
			free_get_env_vars(env->env_variable);
		env->env_variable = get_env_vars(env->first_var);
		execute_cmd(env, token, i);
		i++;
		token = get_next_cmd(token);
	}
	cleanup_pipes(env->pipes, env->nb_cmd - 1);
	wait_all_children(env);
	setup_shell_signals();
}
