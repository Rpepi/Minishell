/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_accessible_directory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:38:07 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/25 12:55:43 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_accessible_directory(char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": no such file or directory\n", 2);
		return (0);
	}
	else if (!S_ISDIR(path_stat.st_mode))
	{
		ft_putstr_fd("minishell: cd :", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": is not a directory\n", 2);
		return (0);
	}
	else if (access(path, R_OK))
	{
		ft_putstr_fd("minishell: cd :", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": no right access to this directory\n", 2);
		return (0);
	}
	return (1);
}
