/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:26:09 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/17 18:09:37 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	add_arg_list(t_cmd *cmd, t_arg *arg)
{
	t_arg	*current;

	if (!cmd || !arg)
		return ;
	if (!cmd->first_arg)
	{
		cmd->first_arg = arg;
		arg->next = NULL;
	}
	else
	{
		current = cmd->first_arg;
		while (current != NULL && current->next != NULL)
		{
			current = current->next;
		}
		current->next = arg;
		arg->next = NULL;
	}
}
