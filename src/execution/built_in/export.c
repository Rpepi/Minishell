/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:49:17 by pepi              #+#    #+#             */
/*   Updated: 2024/09/20 13:02:14 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	check_is_value(char *content)
{
	if (content[0] == '=' && content[1] != '\0')
	{
		return (1);
	}
	return (0);
}

char	*get_value_arg(t_arg *arg, int *index)
{
	char	*str;
	char	*value;
	int		start;

	start = *index;
	value = NULL;
	str = arg->content;
	if (str)
	{
		if (!str[0])
			return (NULL);
		while (str[*index] != '\0')
			*index = *index + 1;
		value = ft_malloc_substrcpy(str, start, *index);
		if (!value)
			return (NULL);
		return (value);
	}
	return (NULL);
}

void	export_arg(t_env *env, char *name, char *value)
{
	t_var	*var;

	var = get_env_var_name(env, name);
	if (!var)
	{
		var = init_variable(name, value, 1);
		if (!var)
			return ;
		add_variables_list(env, var);
	}
	else
	{
		free(name);
		free(var->value);
		var->value = value;
	}
}

int	exec_export(t_env *env, t_cmd *cmd)
{
	char	*name;
	char	*value;
	t_arg	*arg;
	int		index;

	name = NULL;
	value = NULL;
	index = 0;
	if (!cmd->first_arg)
	{
		print_exported_vars(env);
		return (1);
	}
	arg = cmd->first_arg;
	while (arg != NULL)
	{
		name = get_name_arg(arg, &index);
		if (name == NULL)
			return (1);
		value = get_value_arg(arg, &index);
		export_arg(env, name, value);
		index = 0;
		arg = arg->next;
	}
	return (0);
}
