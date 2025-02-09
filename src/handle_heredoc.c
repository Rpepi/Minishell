/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:38:42 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/06 14:41:43 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_heredoc(t_redir *redir, char *line, int *index)
{
	char	*limiter;
	int		start;
	int		end;
	char	*tmp;

	start = *index + 1;
	while (line[start] && is_blank(line[start]))
		start++;
	end = start;
	while (line[end] && !is_blank(line[end]))
		end++;
	limiter = ft_malloc_substrcpy(line, start, end);
	if ((limiter[0] == '"' && limiter[ft_strlen(limiter) - 1] == '"')
		|| (limiter[0] == '\'' && limiter[ft_strlen(limiter) - 1] == '\''))
	{
		tmp = ft_strdup(limiter + 1);
		tmp[ft_strlen(tmp) - 1] = '\0';
		free(limiter);
		limiter = tmp;
	}
	redir->limiter = limiter;
	*index = end - 1;
}
