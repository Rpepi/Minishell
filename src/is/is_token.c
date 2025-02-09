/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:52:44 by ebennace          #+#    #+#             */
/*   Updated: 2024/08/12 16:04:29 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_token_word(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_WORD)
		return (1);
	return (0);
}

int	is_token_file(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_FILE)
		return (1);
	return (0);
}

int	is_token_output_chevron(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_OUTPUT_CHEVRON)
		return (1);
	return (0);
}

int	is_token_basic_redirection(t_token *token)
{
	if (!token)
		return (0);
	if (is_token_output_chevron(token) || is_token_input_chevron(token)
		|| is_token_append_chevron(token))
		return (1);
	return (0);
}

int	is_redir_heredoc(t_redir *redir)
{
	if (!redir)
		return (0);
	if (redir->type == TOKEN_HERE_DOC)
		return (1);
	return (0);
}
