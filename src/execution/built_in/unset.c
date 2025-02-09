/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:30:04 by pepi              #+#    #+#             */
/*   Updated: 2024/09/23 22:10:24 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static void	disconnect_var(t_env *env, t_var *var_to_remove)
{
	if (!env || !var_to_remove)
		return ;
	if (var_to_remove == env->first_var)
	{
		env->first_var = var_to_remove->next;
		if (env->first_var)
			env->first_var->prev = NULL;
	}
	else
	{
		if (var_to_remove->prev)
			var_to_remove->prev->next = var_to_remove->next;
		if (var_to_remove->next)
			var_to_remove->next->prev = var_to_remove->prev;
	}
	free(var_to_remove->name);
	free(var_to_remove->value);
	free(var_to_remove);
}

static void	unset_var(t_env *env, char *name)
{
	t_var	*var;

	if (env->first_var)
	{
		var = env->first_var;
		while (var != NULL)
		{
			if (ft_same(var->name, name))
			{
				disconnect_var(env, var);
				return ;
			}
			var = var->next;
		}
	}
}

static int	invalid_unset(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (is_metachar(arg[i]) || arg[i] == '\0')
		{
			ft_putstr_fd("unset: `': not a valid identifier\n", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	exec_unset(t_env *env, t_cmd *cmd)
{
	char	*name;
	t_arg	*arg;

	if (cmd->first_arg != NULL)
	{
		arg = cmd->first_arg;
		while (arg != NULL)
		{
			if (!invalid_unset(arg->content))
			{
				name = arg->content;
				unset_var(env, name);
			}
			arg = arg->next;
		}
	}
	ft_putstr_fd("unset: `': not a valid identifier\n", 2);
	return (0);
}
