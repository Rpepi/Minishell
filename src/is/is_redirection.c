/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:45:44 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/26 15:03:27 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_pipe(char *line, int i)
{
	if (!line[i])
		return (0);
	if (line[i] == '|')
		return (1);
	return (0);
}

int	is_redir(char *line, int i)
{
	if (!line[i])
		return (0);
	if (line[i] == '|' || is_output_chevrons(line, i)
		|| is_input_chevrons(line, i) || is_append_chevrons(line, i)
		|| is_heredoc(line, i))
		return (1);
	return (0);
}

int	is_file_redir(char *line, int i)
{
	if (is_output_chevrons(line, i) || is_input_chevrons(line, i)
		|| is_append_chevrons(line, i) || is_heredoc(line, i))
		return (1);
	return (0);
}
