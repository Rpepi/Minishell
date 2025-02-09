/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chained_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:44:13 by pepi              #+#    #+#             */
/*   Updated: 2024/08/25 09:30:03 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_var(t_env *env, char **env_variable)
{
	int		i;
	char	*name;
	char	*value;
	t_var	*var;

	i = 0;
	while (env_variable[i])
	{
		name = get_variable_name(env_variable[i]);
		value = get_variable_value(env_variable[i]);
		var = init_variable(name, value, 1);
		add_variables_list(env, var);
		i++;
	}
}

void	add_variables_list(t_env *env, t_var *var)
{
	int		index;
	t_var	*tmp;

	index = 0;
	if (!env->first_var)
	{
		var->index = index;
		env->first_var = var;
	}
	else
	{
		tmp = env->first_var;
		index++;
		while (tmp->next)
		{
			index++;
			tmp = tmp->next;
		}
		var->index = index;
		tmp->next = var;
		var->prev = tmp;
	}
}

char	*get_variable_name(char *variable)
{
	int		end;
	int		start;
	char	*name;

	if (!variable)
		return (NULL);
	end = 0;
	start = 0;
	while (variable[end])
	{
		if (variable[end] == '=')
		{
			end += -1;
			name = ft_malloc_substrcpy(variable, start, end);
			return (name);
		}
		end++;
	}
	name = ft_malloc_substrcpy(variable, start, end);
	return (name);
}

char	*get_variable_value(char *variable)
{
	int		end;
	int		start;
	char	*val;

	if (!variable)
		return (NULL);
	end = 0;
	start = 0;
	while (variable[end])
	{
		if ((variable[end] == '=') && (end + 1 != '\0'))
			start = end + 1;
		end++;
	}
	val = ft_malloc_substrcpy(variable, start, end);
	return (val);
}
