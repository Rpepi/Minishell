/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:34:31 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/25 12:38:21 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_if_token_cmd(t_token *token)
{
	t_token	*token_cmd;

	token_cmd = token;
	while (token_cmd)
	{
		if (token_cmd->id == TOKEN_BUILT_IN || token_cmd->id == TOKEN_BINARY
			|| token_cmd->id == TOKEN_COMMAND)
		{
			return (1);
		}
		if (!token_cmd->prev)
			return (0);
		token_cmd = token_cmd->prev;
	}
	return (0);
}

int	check_word_without_cmd(t_env *env)
{
	t_token	*iter;
	t_word	*word;

	iter = NULL;
	word = NULL;
	if (env->first_token)
		iter = env->first_token;
	while (iter != NULL)
	{
		if (iter->id == TOKEN_WORD)
		{
			word = get_class(iter);
			if (check_if_token_cmd(iter) == 0)
			{
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(word->content, 2);
				ft_putstr_fd(": command not found\n", 2);
				return (0);
			}
		}
		iter = iter->next;
	}
	return (1);
}
