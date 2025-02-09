/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:48:57 by pepi              #+#    #+#             */
/*   Updated: 2024/09/24 10:55:17 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**get_env_bins(t_env *env)
{
	char	*path;
	char	**bins;

	path = get_env_var_value(env, "PATH");
	if (!path)
		return (NULL);
	bins = ft_split(path, ':');
	return (bins);
}

int	test_bin_access(char **bins, char *word)
{
	int		i;
	char	*path;

	i = 0;
	while (bins[i])
	{
		path = ft_strjoin_inter(bins[i], word, '/');
		if (access(path, X_OK & F_OK) == 0)
		{
			free(path);
			return (1);
		}
		free(path);
		i++;
	}
	return (0);
}

int	test_absolute_bin_access(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}
