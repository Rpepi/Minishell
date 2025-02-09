/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:57:43 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/20 14:02:07 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static void	print_env_var(t_var *var)
{
	ft_putstr_fd(var->name, 1);
	ft_putchar_fd('=', 1);
	ft_putstr_fd(var->value, 1);
	ft_putstr_fd("\n", 1);
}

int	exec_env(t_env *env, t_cmd *cmd)
{
	t_var	*var;

	if (!env || !cmd)
		return (1);
	if (cmd->first_arg && cmd->first_arg != NULL)
	{
		ft_putstr_fd("env : illegal option ", 1);
		ft_putstr_fd(cmd->first_arg->content, 1);
		ft_putstr_fd("\n", 1);
		return (1);
	}
	var = env->first_var;
	if (var != NULL)
	{
		print_env_var(var);
		while (var->next != NULL)
		{
			var = var->next;
			print_env_var(var);
		}
	}
	return (0);
}
