/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_relative_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:32:49 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/20 11:32:45 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*convert_relative_path(t_env *env, char *relative_path)
{
	char	*path;
	char	*temp_path;
	char	*new_path;

	path = get_env_var_value(env, "PWD");
	if (!path)
		return (NULL);
	temp_path = ft_strjoin(path, "/");
	if (path)
		free(path);
	if (!temp_path)
		return (NULL);
	new_path = ft_strjoin(temp_path, (relative_path + 2));
	free(temp_path);
	free(relative_path);
	return (new_path);
}
