/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:29:27 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/27 00:02:42 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	find_type_cmd(t_env *env, char *content)
{
	if (is_built_in(content))
		return (7);
	else if (is_bin(env, content))
		return (8);
	return (0);
}

static int	cmd_have_args_to_parse(char *line, int *index)
{
	int	len;

	if (!line || !index || *index < 0)
		return (0);
	len = ft_strlen_int(line);
	if (*index >= len)
		return (0);
	if (is_blank(line[*index]))
		blank_escape(line, index);
	if (*index >= len)
		return (0);
	else if (!is_redir(line, *index) && line[*index] != '\0')
		return (1);
	else if (is_redir(line, *index))
	{
		*index = *index - 1;
		return (0);
	}
	return (0);
}

void	tokenize_cmd(t_env *env, char *content, char *line, int *index)
{
	int		type;
	t_token	*token;
	int		len;

	if (!env || !content || !line || !index || *index < 0)
		return ;
	len = ft_strlen(line);
	type = find_type_cmd(env, content);
	token = init_token();
	if (!token)
		return ;
	token->id = type;
	token->class = init_cmd(content, type);
	(*index)++;
	while (*index < len && cmd_have_args_to_parse(line, index))
	{
		tokenize_arg(env, get_class(token), line, index);
		if (*index < len)
			(*index)++;
	}
	add_token_list(env, token);
}
