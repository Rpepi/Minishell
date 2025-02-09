/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:15:53 by rpepi             #+#    #+#             */
/*   Updated: 2024/08/19 15:30:34 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*get_first_token(t_env *env)
{
	if (env->first_token)
		return (env->first_token);
	return (0);
}

t_cmd	*get_first_cmd(t_env *env)
{
	t_token	*token;

	if (!(get_first_token(env)))
		return (NULL);
	token = get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token))
			return (get_class(token));
		token = token->next;
	}
	return (NULL);
}
