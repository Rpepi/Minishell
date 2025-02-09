/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_cmd_next_pipe.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:12:24 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/26 15:23:59 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_token_cmd_next_pipe(t_env *env)
{
	t_token	*token_npipe;
	t_word	*word;

	token_npipe = NULL;
	if (env->first_token)
		token_npipe = env->first_token;
	while (token_npipe)
	{
		if (token_npipe->id == 17)
		{
			token_npipe = token_npipe->next;
			if ((token_npipe) && (token_npipe->id != 7 && token_npipe->id != 8))
			{
				word = get_class(token_npipe);
				ft_putstr_fd("minishell: ", 2);
				ft_putstr_fd(word->content, 2);
				ft_putstr_fd(": command not found \n", 2);
				return (0);
			}
		}
		token_npipe = token_npipe->next;
	}
	return (1);
}
