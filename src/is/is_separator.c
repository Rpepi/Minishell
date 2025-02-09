/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:11:21 by ebennace          #+#    #+#             */
/*   Updated: 2024/08/26 12:00:52 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_separator(char *line, int i)
{
	if (!line[i])
		return (0);
	if (is_redir(line, i))
		return (1);
	return (0);
}

int	is_delimiter(char *line, int index)
{
	if (is_blank(line[index]) || is_separator(line, index))
		return (1);
	return (0);
}

int	is_variable_delimiter(char *line, int index)
{
	if (is_blank(line[index]) || is_separator(line, index)
		|| line[index] == '$' || is_finish(line[index])
		|| is_quote(line[index]))
		return (1);
	return (0);
}

int	is_argument_separator(t_env *env, char *line, int index)
{
	if (is_separator(line, index) || is_variable(env, line, index))
		return (1);
	return (0);
}

int	is_word_argument_separator(t_env *env, char *line, int index)
{
	if (is_argument_separator(env, line, index) || is_quote(line[index])
		|| is_blank(line[index]))
		return (1);
	return (0);
}
