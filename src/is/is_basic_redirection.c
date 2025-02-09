/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_basic_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:32:17 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/24 19:04:04 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_input_chevrons(char *line, int i)
{
	if (!line[i])
		return (0);
	if (line[i] == '>' && line[i + 1] != '>')
		return (1);
	return (0);
}

int	is_output_chevrons(char *line, int i)
{
	if (!line[i])
		return (0);
	if (line[i] == '<' && line[i + 1] != '<')
		return (1);
	return (0);
}

int	is_append_chevrons(char *line, int i)
{
	if (!line[i])
		return (0);
	if ((line[i] == '>' && line[i + 1] == '>'))
		return (1);
	return (0);
}

int	is_heredoc(char *line, int i)
{
	if (!line[i])
		return (0);
	if ((line[i] == '<' && line[i + 1] == '<'))
		return (1);
	return (0);
}

int	is_basic_redirection_token(int token_id)
{
	return (token_id == TOKEN_INPUT_CHEVRON || token_id == TOKEN_OUTPUT_CHEVRON
		|| token_id == TOKEN_APPEND_CHEVRON || token_id == TOKEN_HERE_DOC);
}
