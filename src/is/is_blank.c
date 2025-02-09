/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:13:57 by ebennace          #+#    #+#             */
/*   Updated: 2024/08/25 17:26:13 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	is_blank_argument(t_env *env, char *line, int index)
{
	if (is_blank(line[index]) && !(is_blank(line[index + 1]))
		&& !(is_separator(line, index + 1)) && !(is_variable(env, line, index))
		&& line[index] != '$' && (line[index + 1]))
		return (1);
	return (0);
}

int	is_blank_before_redirection(char *line, int index)
{
	if (is_blank(line[index]) && is_separator(line, index + 1))
	{
		while (line[index] && is_blank(line[index]))
		{
			if (is_redir(line, index + 1))
			{
				return (1);
			}
			index++;
		}
	}
	return (0);
}

int	is_blank_before_finish(char *line, int index)
{
	if (is_blank(line[index]))
	{
		while (line[index] && is_blank(line[index]))
		{
			if (!line[index + 1])
			{
				return (1);
			}
			index++;
		}
	}
	return (0);
}

int	*blank_escape(char *line, int	*start)
{
	while (line[*start] && line[*start] == ' ')
	{
		if (line[*start] != ' ')
			return (start);
		(*start)++;
	}
	return (start);
}
