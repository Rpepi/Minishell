/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:24:01 by rpepi             #+#    #+#             */
/*   Updated: 2024/08/22 12:26:54 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*get_class(t_token *token)
{
	if (token == NULL)
		return (NULL);
	if (is_token_cmd(token))
		return ((t_cmd *)token->class);
	else if (is_token_redirection(token))
		return ((t_redir *)token->class);
	else if (is_token_file(token))
		return ((t_file *)token->class);
	else if (is_token_word(token))
		return ((t_word *)token->class);
	return (NULL);
}
