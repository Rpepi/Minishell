/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:06:27 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/20 11:36:29 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_echo(t_cmd *cmd)
{
	if (ft_same("echo", cmd->content))
		return (1);
	return (0);
}

int	is_cd(t_cmd *cmd)
{
	if (ft_same("cd", cmd->content))
		return (1);
	return (0);
}

int	is_pwd(t_cmd *cmd)
{
	if (ft_same("pwd", cmd->content))
		return (1);
	return (0);
}

int	is_env(t_cmd *cmd)
{
	if (ft_same("env", cmd->content))
		return (1);
	return (0);
}

int	is_export(t_cmd *cmd)
{
	if (ft_same("export", cmd->content))
		return (1);
	return (0);
}
