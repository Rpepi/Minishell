/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inversion_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:47:18 by pepi              #+#    #+#             */
/*   Updated: 2024/09/24 20:50:40 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	invert_cmd_before_redir(t_env *env, t_token *cmd_token,
		t_token *redir_token)
{
	if (cmd_token->prev)
		cmd_token->prev->next = cmd_token->next;
	if (cmd_token->next)
		cmd_token->next->prev = cmd_token->prev;
	cmd_token->prev = redir_token->prev;
	cmd_token->next = redir_token;
	if (redir_token->prev)
		redir_token->prev->next = cmd_token;
	else
		env->first_token = cmd_token;
	redir_token->prev = cmd_token;
}

void	check_inversion_redir(t_env *env)
{
	t_token	*token;
	t_token	*cmd_token;

	cmd_token = NULL;
	if (!env->first_token || !is_basic_redirection_token(env->first_token->id))
		return ;
	token = env->first_token;
	while (token && !is_token_cmd(token))
	{
		if (token->id == TOKEN_PIPE)
			return ;
		token = token->next;
	}
	if (token && is_token_cmd(token))
	{
		cmd_token = token;
		invert_cmd_before_redir(env, cmd_token, env->first_token);
	}
}
