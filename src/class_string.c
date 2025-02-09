/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:27:26 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/24 20:51:19 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	token_before_is_not_word(t_env *env)
{
	t_token	*token;

	token = get_last_token(env);
	if (token == NULL)
		return (1);
	if (token->id == TOKEN_INPUT_CHEVRON || token->id == TOKEN_OUTPUT_CHEVRON
		|| token->id == TOKEN_REDIRECTION || token->id == TOKEN_APPEND_CHEVRON
		|| token->id == TOKEN_HERE_DOC)
	{
		if (!token->prev)
			return (1);
		token = token->prev;
		if (token->id == TOKEN_BINARY || token->id == TOKEN_COMMAND
			|| token->id == TOKEN_BUILT_IN)
			return (0);
	}
	if (token->id == 2)
		return (0);
	return (1);
}

t_token	*tokenize_word(t_env *env, char *content, int id)
{
	t_token	*token;

	token = init_token();
	token->id = id;
	token->class = init_word(content, id);
	add_token_list(env, token);
	return (token);
}

void	class_string(t_env *env, char *line, int *index)
{
	char	*content;
	int		start;

	start = *index;
	string_detection(line, index);
	content = ft_malloc_substrcpy(line, start, *index);
	if (is_cmd(env, content) && token_before_is_not_word(env))
	{
		tokenize_cmd(env, content, line, index);
	}
	else
		tokenize_word(env, content, TOKEN_WORD);
}
