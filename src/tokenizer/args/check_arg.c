/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:35:24 by pepi              #+#    #+#             */
/*   Updated: 2024/09/26 14:53:43 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*exec_type_arg_quote(t_env *env, char *part_arg, int *i)
{
	char	*new_part_arg;
	char	*temp;

	if (part_arg[0] == '\'')
	{
		new_part_arg = remove_quote_from_content(part_arg);
		*i = *i + 1;
		return (new_part_arg);
	}
	else if (part_arg[0] == '\"')
	{
		temp = remove_quote_from_content(part_arg);
		if (!temp)
			return (NULL);
		new_part_arg = handle_double_quote(env, temp);
		free(temp);
		*i = *i + 1;
		return (new_part_arg);
	}
	return (NULL);
}

char	*exec_type_arg(t_env *env, char *part_arg, int *i)
{
	char	*new_part_arg;

	new_part_arg = NULL;
	if (ft_same(part_arg, "$?"))
	{
		new_part_arg = ft_malloc_strcpy(ft_itoa(env->last_exit_status));
		free(part_arg);
		return (new_part_arg);
	}
	new_part_arg = exec_type_arg_quote(env, part_arg, i);
	if (new_part_arg)
		return (new_part_arg);
	if (is_dollar_word(part_arg, 0))
	{
		new_part_arg = handle_dollar_word(env, part_arg);
		return (new_part_arg);
	}
	return (part_arg);
}

char	*process_arg_part(t_env *env, char *content, int *i, int *flag)
{
	char	*part_arg;
	char	*new_content;
	int		start;

	start = *i;
	*i = is_different_type(content, *i, flag);
	part_arg = ft_malloc_substrcpy(content, start, *i);
	if (*flag == 4)
		*i = *i + 1;
	part_arg = exec_type_arg(env, part_arg, i);
	if (part_arg)
	{
		new_content = ft_strdup(part_arg);
		if (part_arg != content)
			free(part_arg);
	}
	else
		new_content = NULL;
	if (*flag == 1)
		(*i)++;
	if (*flag == 2)
		(*i)++;
	if (*flag != 0)
		*flag = 0;
	return (new_content);
}

char	*check_arg(t_env *env, char *content)
{
	char	*new_content;
	char	*part_content;
	int		i;
	int		len;
	int		flag;

	i = 0;
	flag = 0;
	len = ft_strlen(content);
	new_content = NULL;
	while (i < len)
	{
		part_content = process_arg_part(env, content, &i, &flag);
		if (part_content)
		{
			if (new_content == NULL)
				new_content = ft_malloc_strcpy(part_content);
			else
				new_content = ft_strjoin_free(new_content, part_content);
			free (part_content);
			part_content = NULL;
		}
	}
	return (new_content);
}

char	*handle_dollar_word(t_env *env, char *content)
{
	char	*name;
	char	*value;
	char	*new_content;

	name = get_name_without_dollar(content);
	if (!name)
	{
		return (NULL);
	}
	value = get_env_var_value(env, name);
	if (!value)
	{
		free(content);
		free(name);
		return (NULL);
	}
	free(content);
	free(name);
	new_content = ft_strdup(value);
	return (new_content);
}
