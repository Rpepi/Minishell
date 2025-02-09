/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:11:53 by ebennace          #+#    #+#             */
/*   Updated: 2024/08/12 16:04:17 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_token_redirection(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_INPUT_CHEVRON || token->id == TOKEN_OUTPUT_CHEVRON
		|| token->id == TOKEN_REDIRECTION || token->id == TOKEN_APPEND_CHEVRON
		|| token->id == TOKEN_HERE_DOC || token->id == TOKEN_PIPE)
		return (1);
	return (0);
}

int	is_token_pipe(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_PIPE)
		return (1);
	return (0);
}

int	is_token_heredoc(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_HERE_DOC)
		return (1);
	return (0);
}

int	is_token_input_chevron(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_INPUT_CHEVRON)
		return (1);
	return (0);
}

int	is_token_append_chevron(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_APPEND_CHEVRON)
		return (1);
	return (0);
}
