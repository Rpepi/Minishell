/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:15:21 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/04 11:32:05 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	type_of_redirect(char *content)
{
	if (is_pipe(content, 0))
		return (TOKEN_PIPE);
	else if (is_heredoc(content, 0))
		return (TOKEN_HERE_DOC);
	else if (is_input_chevrons(content, 0))
		return (TOKEN_INPUT_CHEVRON);
	else if (is_append_chevrons(content, 0))
		return (TOKEN_APPEND_CHEVRON);
	else if (is_output_chevrons(content, 0))
		return (TOKEN_OUTPUT_CHEVRON);
	return (0);
}

t_redir	*init_redirection(int type, char *content)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->fd_in = STDIN_FILENO;
	redir->fd_out = STDOUT_FILENO;
	redir->limiter = NULL;
	redir->content = content;
	redir->file_name = NULL;
	return (redir);
}

t_token	*create_token_redir(char *line, int index, int *new_index)
{
	char	*content;
	int		type;
	t_token	*token;

	content = ft_malloc_substrcpy(line, index, *new_index);
	type = type_of_redirect(content);
	token = init_token();
	token->id = type;
	token->class = init_redirection(type, content);
	if (is_heredoc(content, 0))
		handle_heredoc(get_class(token), line, new_index);
	return (token);
}

void	class_redir(t_env *env, char *line, int *index)
{
	t_token	*token;
	int		start;

	start = 0;
	start = start + *index;
	if (!is_pipe(line, *index))
	{
		if (is_heredoc(line, start) || is_append_chevrons(line, start))
			*index = *index + 1;
	}
	token = create_token_redir(line, start, index);
	if (is_token_basic_redirection(token))
		find_next_file(env, get_class(token), line, index);
	add_token_list(env, token);
}
