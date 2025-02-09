/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:03:44 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/07 10:51:08 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static int	handle_exit_arg(t_env *env, t_cmd *cmd)
{
	int	exit_status;

	exit_status = 0;
	if (cmd->first_arg->next)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	env->last_exit_status = ft_atoi(cmd->first_arg->content);
	if (env->last_exit_status == 0 && cmd->first_arg->content[0] != '0')
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(cmd->first_arg->content, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_status = 2;
	}
	return (exit_status);
}

int	exec_exit(t_env *env, t_cmd *cmd)
{
	int	exit_status;

	exit_status = 0;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (!cmd->first_arg)
	{
		exit_status = env->last_exit_status;
	}
	else
	{
		exit_status = handle_exit_arg(env, cmd);
		if (exit_status == 1)
			return (exit_status);
	}
	free_tokens(env);
	free_env(env);
	exit(exit_status);
}
