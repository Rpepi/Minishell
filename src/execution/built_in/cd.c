/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:17:03 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/25 12:52:30 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static int	change_to_home_directory(t_env *env)
{
	if (chdir(get_env_var_value(env, "HOME")) == -1)
		return (1);
	return (0);
}

static int	change_to_specified_directory(const char *path)
{
	if (is_accessible_directory((char *) path))
	{
		if (chdir(path) == -1)
			return (1);
		return (0);
	}
	return (1);
}

static int	update_pwd_variables(t_env *env, const char *old_pwd)
{
	char	*new_pwd;

	update_var_value_with_name(env, "OLDPWD", (char *)old_pwd);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
	{
		update_var_value_with_name(env, "PWD", new_pwd);
		free(new_pwd);
		return (0);
	}
	write(STDERR_FILENO, "cd: error retrieving current directory\n", 40);
	return (1);
}

int	exec_cd(t_env *env, t_cmd *cmd)
{
	char	*old_pwd;
	int		result;

	old_pwd = get_env_var_value(env, "PWD");
	if (!cmd->first_arg || ft_same("~", cmd->first_arg->content))
		result = change_to_home_directory(env);
	else
		result = change_to_specified_directory(cmd->first_arg->content);
	if (result == 0)
		result = update_pwd_variables(env, old_pwd);
	return (result);
}
