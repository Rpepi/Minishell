/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:28:48 by pepi              #+#    #+#             */
/*   Updated: 2024/09/20 12:29:23 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	find_end_dollar_word(char *content, int index, int *flag)
{
	int	i;

	i = index + 1;
	while (content[i] != '\0' && content[i] != ' ' && content[i] != '\"'
		&& content[i] != '\'' && !is_metachar(content[i]))
	{
		if (content[i] == '$')
		{
			*flag = 2;
			return (i - 1);
		}
		i++;
	}
	*flag = 4;
	return (i - 1);
}

int	is_different_type_quote(char *content, int index)
{
	int	i;

	i = index;
	if (content[i] == '\'' || content[i] == '\"')
	{
		i = find_end_quote(content, i);
		return (i);
	}
	return (-1);
}

int	is_different_type(char *content, int index, int *flag)
{
	int	i;

	i = is_different_type_quote(content, index);
	if (i != -1)
		return (i);
	i = index;
	if (content[i] == '$' && content[i + 1] == '?')
	{
		*flag = 2;
		return (i + 1);
	}
	else if (is_dollar_word(content, i))
	{
		i = find_end_dollar_word(content, i, flag);
		return (i);
	}
	else
		*flag = 1;
	return (i);
}
