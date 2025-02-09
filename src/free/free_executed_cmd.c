/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_executed_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:03:30 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/18 22:40:55 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_all_tokens(t_token *token)
{
	t_token	*next;

	next = token->next;
	while (token)
	{
		if (token->id == TOKEN_BINARY || token->id == TOKEN_BUILT_IN)
			free_cmd(get_class(token));
		if (token->id == TOKEN_WORD)
			free_word(get_class(token));
		if (token->id == TOKEN_REDIRECTION)
			free_redir(get_class(token));
		token = next;
		if (next)
			next = next->next;
	}
}
