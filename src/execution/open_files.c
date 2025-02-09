/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:31:48 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 11:55:07 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	handle_input_redirection_ofile(int new_fd)
{
	if (dup2(new_fd, STDIN_FILENO) == -1)
	{
		close(new_fd);
		return (-1);
	}
	return (0);
}

int	open_file(t_redir *redir, int prev_fd, int flags, mode_t permissions)
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
	if (ft_same(redir->content, "<"))
		return (handle_input_redirection_ofile(new_fd));
	else if (ft_same(redir->content, ">") || ft_same(redir->content, ">>"))
		return (handle_output_redirection_ofile(new_fd));
	return (new_fd);
}

int	open_here_doc(t_redir *redir, t_env *env)
{
	int	new_fd;

	new_fd = here_doc(redir, env);
	if (new_fd == -1)
		return (-1);
	if (dup2(new_fd, STDIN_FILENO) == -1)
	{
		close(new_fd);
		return (-1);
	}
	return (new_fd);
}

int	open_files(t_token *token, t_env *env)
{
	t_token	*iter;
	t_redir	*redir;
	int		fd_in;
	int		fd_out;

	fd_in = -2;
	fd_out = -2;
	iter = token;
	while (iter)
	{
		iter = get_next_redir_token(iter);
		if (iter == NULL)
			break ;
		redir = get_class(iter);
		if (handle_redirection(redir, &fd_in, &fd_out, env))
			return (1);
	}
	return (0);
}
