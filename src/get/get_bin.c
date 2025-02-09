/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:47:33 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/25 11:16:01 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_path_specified(const char *path)
{
	return (ft_strchr(path, '/') != NULL);
}

static int	is_executable(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == 0 && S_ISREG(st.st_mode) && access(path, X_OK) == 0)
		return (1);
	return (0);
}

static char	*join_and_check_path(char **all_paths, const char *cmd)
{
	char	*full_path;
	char	*tmp;
	int		i;

	i = 0;
	while (all_paths[i])
	{
		tmp = ft_strjoin(all_paths[i], "/");
		if (!tmp)
			return (NULL);
		full_path = ft_strjoin_free(tmp, cmd);
		if (!full_path)
		{
			free(tmp);
			return (NULL);
		}
		if (is_executable(full_path))
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

static char	*search_in_path(const char *cmd, const char *path)
{
	char	**all_paths;
	char	*result;

	all_paths = ft_split(path, ':');
	if (!all_paths)
		return (NULL);
	result = join_and_check_path(all_paths, cmd);
	free_string_array(all_paths);
	return (result);
}

char	*get_bin(t_cmd *cmd, t_env *env)
{
	char	*path;
	char	*result;

	if (!cmd || !cmd->content)
		return (NULL);
	if (is_path_specified(cmd->content))
	{
		if (is_executable(cmd->content))
			return (ft_strdup(cmd->content));
		return (NULL);
	}
	path = get_env_var_value(env, "PATH");
	if (!path)
		return (NULL);
	result = search_in_path(cmd->content, path);
	return (result);
}
