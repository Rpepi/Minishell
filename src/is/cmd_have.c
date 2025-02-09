/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_have.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:46:01 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/16 11:59:58 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	cmd_have_args(t_cmd *cmd)
{
	if (cmd->first_arg)
		return (1);
	return (0);
}

int	cmd_have_argument(t_cmd *cmd)
{
	if (is_env(cmd) || is_pwd(cmd) || is_cd(cmd)
		|| is_exit(cmd) || is_export(cmd) || is_echo(cmd))
		return (1);
	if ((cmd->args || cmd->arg))
		return (1);
	return (0);
}

int	cmd_have_args_array(t_cmd *cmd)
{
	if (cmd->args)
		return (1);
	return (0);
}
