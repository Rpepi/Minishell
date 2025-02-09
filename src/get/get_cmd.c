/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:34:28 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/25 11:16:36 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*get_next_cmd(t_token *token)
{
	t_token	*iter;

	iter = NULL;
	if (token->next)
		iter = token->next;
	while (iter)
	{
		if (iter->id == TOKEN_BINARY || iter->id == TOKEN_BUILT_IN)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

int	get_nb_cmds(t_token *token)
{
	t_token	*iter;
	int		i;

	iter = NULL;
	if (token)
		iter = token;
	i = 0;
	while (iter)
	{
		if (iter->id == TOKEN_BINARY || iter->id == TOKEN_BUILT_IN)
			i++;
		if (!iter->next)
			break ;
		iter = iter->next;
	}
	return (i);
}

t_token	*get_first_cmd_token(t_token *token)
{
	t_token	*iter;

	iter = NULL;
	if (token)
		iter = token;
	while (iter)
	{
		if (iter->id == TOKEN_BINARY || iter->id == TOKEN_BUILT_IN)
			return (iter);
		if (!iter->next)
			break ;
		iter = iter->next;
	}
	return (NULL);
}
