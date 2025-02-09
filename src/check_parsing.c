/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:32:52 by pepi              #+#    #+#             */
/*   Updated: 2024/09/24 18:57:46 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_content_token(t_token *token)
{
	t_word	*word;

	if (!token || !token->class)
		return (NULL);
	word = get_class(token);
	if (!word)
		return (NULL);
	return (word->content);
}

int	check_parsing(t_env *env)
{
	char	*content;

	if (env->error_in_parsing > 0)
		return (0);
	if (!is_token_cmd(env->first_token)
		&& !is_token_redirection(env->first_token))
	{
		content = get_content_token(env->first_token);
		if (content)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(content, 2);
			ft_putstr_fd(": command not found\n", 2);
		}
		return (0);
	}
	return (1);
}
