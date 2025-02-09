/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:13:34 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/23 12:04:06 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_token_cmd(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_BUILT_IN || token->id == TOKEN_BINARY
		|| token->id == TOKEN_COMMAND)
		return (1);
	return (0);
}

int	is_token_bin(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_BINARY)
		return (1);
	return (0);
}

int	is_token_built_in(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_BUILT_IN)
		return (1);
	return (0);
}

int	is_cmd_bin(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->id == TOKEN_BINARY || cmd->id == TOKEN_COMMAND)
		return (1);
	return (0);
}

int	is_cmd_built_in(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->id == TOKEN_BUILT_IN || cmd->id == TOKEN_COMMAND)
		return (1);
	return (0);
}
