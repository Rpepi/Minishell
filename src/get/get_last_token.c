/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:28:18 by pepi              #+#    #+#             */
/*   Updated: 2024/09/24 18:57:23 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*get_last_token(t_env *env)
{
	t_token	*token;

	if (env->first_token == NULL)
	{
		return (NULL);
	}
	token = env->first_token;
	while (token->next)
		token = token->next;
	return (token);
}
