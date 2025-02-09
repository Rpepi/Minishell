/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:06:36 by pepi              #+#    #+#             */
/*   Updated: 2024/09/26 12:39:09 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_cmd	*find_token_cmd_before(t_token *token)
{
	t_cmd	*cmd;

	cmd = NULL;
	while (token)
	{
		if (token->id == TOKEN_BUILT_IN || token->id == TOKEN_BINARY
			|| token->id == TOKEN_COMMAND)
		{
			cmd = get_class(token);
			return (cmd);
		}
		if (!token->prev)
			return (NULL);
		token = token->prev;
	}
	return (NULL);
}

static void	add_token_word_to_cmd(t_env *env, t_token *token)
{
	t_cmd	*cmd;
	t_arg	*arg;
	t_word	*word;
	char	*content;
	int		type;

	type = 0;
	(void)env;
	content = NULL;
	arg = NULL;
	word = NULL;
	cmd = find_token_cmd_before(token);
	if (token->id == 2 && cmd != NULL)
	{
		word = get_class(token);
		content = ft_strdup(word->content);
		content = check_arg(env, content);
		type = find_type_arg(content);
		arg = init_arg(content, type);
		if (arg != NULL)
		{
			add_arg_list(cmd, arg);
		}
	}
}

void	check_token_word(t_env *env)
{
	t_token	*token;

	token = NULL;
	if (env->first_token)
		token = env->first_token;
	while (token != NULL)
	{
		if (token->id == TOKEN_WORD)
			add_token_word_to_cmd(env, token);
		token = token->next;
	}
}
