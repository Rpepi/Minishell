/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:26:46 by pepi              #+#    #+#             */
/*   Updated: 2024/09/25 11:16:54 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_part_of_pipeline(t_token *token)
{
	t_token	*current;

	current = NULL;
	if (token->next)
		current = token->next;
	while (current)
	{
		if (current->id == TOKEN_PIPE)
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}
