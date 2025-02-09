/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:57:44 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/20 12:46:54 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	add_token_to_empty_list(t_env *env, t_token *token)
{
	token->next = NULL;
	token->prev = NULL;
	env->first_token = token;
}

static void	add_token_to_existing_list(t_env *env, t_token *token)
{
	t_token	*iter;

	iter = env->first_token;
	if (env->first_token->next == NULL)
		env->first_token->next = token;
	else
	{
		while (iter->next != NULL)
		{
			iter = iter->next;
		}
	}
	if (iter != NULL)
	{
		iter->next = token;
		token->prev = iter;
	}
}

void	add_token_list(t_env *env, t_token *token)
{
	if (env == NULL || token == NULL)
		return ;
	token->next = NULL;
	token->prev = NULL;
	if (env->first_token == NULL)
		add_token_to_empty_list(env, token);
	else
		add_token_to_existing_list(env, token);
}
