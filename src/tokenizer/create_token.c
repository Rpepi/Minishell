/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:37:22 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/21 23:48:54 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*create_token_word(char *content, int id)
{
	t_token	*token;

	token = init_token();
	token->id = id;
	token->class = init_word(content, id);
	return (token);
}

t_arg	*create_arg(char *content, int id)
{
	t_arg	*arg;

	arg = init_arg(content, id);
	return (arg);
}

t_token	*create_token_command(int id, char *content)
{
	t_token	*token;

	token = init_token();
	token->id = id;
	token->class = init_cmd(content, id);
	return (token);
}

t_token	*create_token_file(char *name, int id)
{
	t_token	*token;

	token = init_token();
	token->id = id;
	token->class = init_file(name);
	return (token);
}
