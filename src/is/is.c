/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:53:15 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/18 00:25:34 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_not_null(char c, char d)
{
	if (c && d)
		return (1);
	return (0);
}

int	is_null(char *line)
{
	if (line == NULL)
		return (1);
	return (0);
}

int	is_value_null(char *value)
{
	if (value[0] == '\0')
		return (1);
	return (0);
}

int	is_back_slash(char c)
{
	if (c == '\\')
		return (1);
	return (0);
}

int	is_string(char *line, int i)
{
	if (line[i] != ' '
		&& !is_redir(line, i))
		return (1);
	return (0);
}
