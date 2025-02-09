/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:42:53 by pepi              #+#    #+#             */
/*   Updated: 2024/09/26 23:57:29 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*init_env(char **env_tab)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->first_var = NULL;
	env->first_token = NULL;
	env->last_exit_status = 0;
	env->error_in_parsing = 0;
	env->env_variable = NULL;
	env->env_variable = NULL;
	add_var(env, env_tab);
	ft_free_dtab(env_tab);
	return (env);
}

t_var	*init_variable(char *name, char *value, int id)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->index = -1;
	var->id = id;
	var->name = name;
	var->value = value;
	var->next = NULL;
	var->prev = NULL;
	return (var);
}
