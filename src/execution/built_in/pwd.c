/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:08:36 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 12:41:14 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	exec_pwd(void)
{
	char	*path;
	int		result;

	path = getcwd(NULL, 0);
	if (path)
	{
		ft_putstr_fd(path, 1);
		ft_putstr_fd("\n", 1);
		result = 0;
	}
	else
	{
		ft_putstr_fd("Invalid path for current directory\n", 2);
		result = 1;
	}
	free(path);
	return (result);
}
