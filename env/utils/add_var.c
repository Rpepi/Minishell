/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:51:48 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/20 11:24:45 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_var	*update_var_value_with_name(t_env *env, char *name, char *new_value)
{
	t_var	*var;
	char	*value_copy;

	var = get_first_env_var(env);
	if (!var)
		return (NULL);
	while (var && !ft_same(var->name, name))
		var = var->next;
	if (!var)
		return (NULL);
	value_copy = ft_strdup(new_value);
	if (!value_copy)
		return (NULL);
	if (var->value)
		free(var->value);
	var->value = value_copy;
	return (var);
}
