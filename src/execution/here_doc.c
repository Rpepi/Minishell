/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:23:17 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 11:37:39 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	setup_here_doc(int *fd, int *tty_fd)
{
	if (pipe(fd) == -1)
		return (-1);
	*tty_fd = open("/dev/tty", O_RDONLY);
	if (*tty_fd == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	return (0);
}

static void	write_expanded_line(int fd, char *line, t_env *env)
{
	char	*expanded_line;

	expanded_line = expand_heredoc_line(line, env);
	if (expanded_line)
	{
		ft_putstr_fd(expanded_line, fd);
		free(expanded_line);
	}
	free(line);
}

static int	read_here_doc(int tty_fd, int fd_write, t_redir *redir, t_env *env)
{
	char	*line;
	size_t	limiter_len;

	limiter_len = ft_strlen(redir->limiter);
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(tty_fd);
		if (!line)
			break ;
		if (ft_strncmp(line, redir->limiter, limiter_len) == 0
			&& (line[limiter_len] == '\n' || line[limiter_len] == '\0'))
		{
			free(line);
			break ;
		}
		write_expanded_line(fd_write, line, env);
	}
	return (0);
}

int	here_doc(t_redir *redir, t_env *env)
{
	int	fd[2];
	int	tty_fd;

	if (setup_here_doc(fd, &tty_fd) == -1)
		return (-1);
	read_here_doc(tty_fd, fd[1], redir, env);
	close(tty_fd);
	close(fd[1]);
	return (fd[0]);
}
