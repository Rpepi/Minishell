/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_only_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:11:51 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 10:22:39 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	open_file_only_redir(t_redir *redir, int prev_fd, int flags,
							mode_t permissions)
{
	char	*file_name;
	int		new_fd;

	if (prev_fd != -2)
		close(prev_fd);
	file_name = redir->file_name;
	new_fd = open(file_name, flags, permissions);
	if (new_fd == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (-1);
	}
	return (new_fd);
}

static int	open_redirection(t_token *token, int fd, t_env *env)
{
	t_redir	*redir;

	redir = get_class(token);
	if (!redir || !redir->content)
		return (0);
	else if (ft_same(redir->content, ">"))
		fd = open_file_only_redir(redir, fd,
				O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (ft_same(redir->content, ">>"))
		fd = open_file_only_redir(redir, fd,
				O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if (ft_same(redir->content, "<"))
		fd = open_file_only_redir(redir, fd, O_RDONLY, 0);
	else if (ft_same(redir->content, "<<"))
		fd = here_doc(redir, env);
	close(fd);
	return (0);
}

int	handle_only_redir(t_token *token, t_env *env)
{
	t_token	*current;
	int		fd;
	int		result;

	current = token;
	result = 0;
	fd = -2;
	while (current && result == 0)
	{
		if (current->id == TOKEN_INPUT_CHEVRON
			|| current->id == TOKEN_OUTPUT_CHEVRON
			|| current->id == TOKEN_APPEND_CHEVRON
			|| current->id == TOKEN_HERE_DOC)
		{
			result = open_redirection(current, fd, env);
		}
		current = current->next;
	}
	return (result);
}
