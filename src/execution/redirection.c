/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:28:34 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 22:15:12 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*get_next_redir_token(t_token *token)
{
	t_token	*iter;

	iter = token->next;
	while (iter && (iter->id != TOKEN_BUILT_IN && iter->id != TOKEN_BINARY))
	{
		if (iter->id == TOKEN_APPEND_CHEVRON
			|| iter->id == TOKEN_INPUT_CHEVRON
			|| iter->id == TOKEN_OUTPUT_CHEVRON
			|| iter->id == TOKEN_HERE_DOC)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

int	handle_output_redirection_ofile(int new_fd)
{
	if (dup2(new_fd, STDOUT_FILENO) == -1)
	{
		write(2, "Error redirecting output: ", 27);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		close(new_fd);
		return (-1);
	}
	return (0);
}

int	handle_redirection(t_redir *redir, int *fd_in, int *fd_out, t_env *env)
{
	if (ft_same(redir->content, "<"))
		*fd_in = open_file(redir, *fd_in, O_RDONLY, 0);
	else if (ft_same(redir->content, ">"))
		*fd_out = open_file(redir, *fd_out, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (ft_same(redir->content, ">>"))
		*fd_out = open_file(redir, *fd_out,
				O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if (ft_same(redir->content, "<<"))
		*fd_in = open_here_doc(redir, env);
	if (*fd_in == -1 || *fd_out == -1)
		return (1);
	return (0);
}

int	has_redir(t_token *token, char *content)
{
	t_token	*next;
	t_redir	*redir;

	next = token;
	while (next)
	{
		next = get_next_redir_token(next);
		if (next == NULL)
			break ;
		redir = get_class(next);
		if (redir && redir->content && ft_same(redir->content, content))
			return (1);
	}
	return (0);
}
