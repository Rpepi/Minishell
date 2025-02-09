/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:01:29 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/06 16:03:13 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_env(t_env *env)
{
	t_var	*var;
	t_var	*tmp;

	if (!env)
		return ;
	var = NULL;
	tmp = NULL;
	if (env->env_variable)
		ft_free_dtab(env->env_variable);
	if (env->first_var)
	{
		var = env->first_var;
		while (var != NULL)
		{
			tmp = var;
			var = var->next;
			free_env_var(tmp);
		}
	}
}

void	free_env_var(t_var *var)
{
	if (var->name)
		free(var->name);
	if (var->value)
		free(var->value);
	free(var);
}

static void	free_token_class_redir(t_token *token)
{
	t_redir	*pipe;

	if (token->id == TOKEN_INPUT_CHEVRON
		|| token->id == TOKEN_OUTPUT_CHEVRON
		|| token->id == TOKEN_APPEND_CHEVRON
		|| token->id == TOKEN_HERE_DOC)
	{
		free_redir(get_class(token));
	}
	else if (token->id == TOKEN_PIPE)
	{
		pipe = get_class(token);
		free(pipe->content);
		free(pipe->limiter);
		free(pipe);
	}
}

void	free_token_class(t_token *token)
{
	t_word	*word;

	if (!token || !token->class)
		return ;
	if (token->id == TOKEN_BUILT_IN || token->id == TOKEN_BINARY)
		free_cmd(get_class(token));
	else if (token->id == TOKEN_WORD)
	{
		word = get_class(token);
		free_word(word);
		free(word);
	}
	else if (token->id == TOKEN_FILE)
		free_file(get_class(token));
	else
		free_token_class_redir(token);
	token->class = NULL;
}

void	free_tokens(t_env *env)
{
	t_token	*tmp_token;
	t_token	*token;

	token = NULL;
	if (env->first_token)
		token = env->first_token;
	while (token != NULL)
	{
		tmp_token = token;
		token = token->next;
		free_token_class(tmp_token);
		free(tmp_token);
	}
	env->first_token = NULL;
}
