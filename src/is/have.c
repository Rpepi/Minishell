/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:52:01 by ebennace          #+#    #+#             */
/*   Updated: 2024/08/12 16:16:45 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	have_token(t_env *env)
{
	if (env->first_token)
		return (1);
	return (0);
}

int	token_have_args(t_token *token)
{
	if (((t_cmd *)token->class)->first_arg)
		return (1);
	return (0);
}

int	have_token_redirection(t_env *env)
{
	t_token	*token;

	if (!(have_token(env)))
		return (0);
	token = get_first_token(env);
	while (token)
	{
		if (is_token_redirection(token))
			return (1);
		token = token->next;
	}
	return (0);
}
