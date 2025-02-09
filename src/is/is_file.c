/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:50:12 by ebennace          #+#    #+#             */
/*   Updated: 2024/08/21 16:23:31 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_after_redirect(char *line, int index)
{
	index--;
	while (index >= 0)
	{
		if (!(is_blank(line[index])))
		{
			if (is_file_redir(line, index))
				return (1);
			return (0);
		}
		index--;
	}
	return (0);
}

int	is_after_heredoc(char *line, int index)
{
	index--;
	while (index >= 0)
	{
		if (!(is_blank(line[index])))
		{
			if (is_heredoc(line, index))
				return (1);
			return (0);
		}
		index--;
	}
	return (0);
}

int	is_limiter(char *line, int i)
{
	if (is_after_heredoc(line, i) && !(is_file(line, i)))
		return (1);
	return (0);
}

int	is_file(char *line, int i)
{
	while (line[i])
	{
		if ((line[i] == '.')
			&& (line[i + 1] != '\0' || line[i + 1] != ' '))
			return (1);
		i++;
	}
	return (0);
}
