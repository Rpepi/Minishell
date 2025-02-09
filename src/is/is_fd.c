/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:28:36 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/23 12:48:14 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_standard_fd(int fd)
{
	if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
	{
		ft_putstr_fd("not standard fd is ", 2);
		ft_putnbr_fd(fd, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}

int	is_not_standard_fd(int fd)
{
	if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO)
		return (1);
	return (0);
}

int	cmd_have_standart_fd(t_cmd *cmd)
{
	if (is_standard_fd(cmd->fd_in) && is_standard_fd(cmd->fd_out))
		return (1);
	return (0);
}
