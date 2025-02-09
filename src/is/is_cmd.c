/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:26:55 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/23 18:06:37 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_bin(t_env *env, char *word)
{
	char	**bins;

	bins = get_env_bins(env);
	if (!bins)
		return (0);
	else if (test_absolute_bin_access(word) || test_bin_access(bins, word))
	{
		ft_free_dtab(bins);
		return (1);
	}
	ft_free_dtab(bins);
	return (0);
}

int	is_cmd(t_env *env, char *word)
{
	if (is_bin(env, word) || is_built_in(word))
		return (1);
	return (0);
}

int	is_built_in(char *content)
{
	if (ft_same(content, "echo"))
		return (1);
	else if (ft_same(content, "cd"))
		return (1);
	else if (ft_same(content, "pwd"))
		return (1);
	else if (ft_same(content, "env"))
		return (1);
	else if (ft_same(content, "export"))
		return (1);
	else if (ft_same(content, "unset"))
		return (1);
	else if (ft_same(content, "exit"))
		return (1);
	return (0);
}

int	is_unset(t_cmd *cmd)
{
	if (ft_same("unset", cmd->content))
		return (1);
	return (0);
}

int	is_exit(t_cmd *cmd)
{
	if (ft_same("exit", cmd->content))
		return (1);
	return (0);
}
