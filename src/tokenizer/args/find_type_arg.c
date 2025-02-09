/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:43:05 by pepi              #+#    #+#             */
/*   Updated: 2024/11/06 10:23:14 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*remove_quote_from_content(char *content)
{
	int		len;
	char	*new_content;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = ft_strlen_int(content) - 2;
	new_content = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_content)
		return (NULL);
	while (content[i + 1] != '\0')
	{
		new_content[j] = content[i];
		i++;
		j++;
	}
	new_content[j] = '\0';
	free(content);
	return (new_content);
}

char	*handle_dollar_var(t_env *env, char *content, int *i, int len)
{
	int		start;
	int		end;
	char	*var_name;
	char	*var_value;

	start = *i;
	end = start + 1;
	while (end < len && (ft_isalnum(content[end]) || content[end] == '_'
			|| content[end] == '?'))
		end++;
	var_name = ft_malloc_substrcpy(content, start + 1, end - 1);
	if (!var_name)
		return (NULL);
	var_value = NULL;
	if (ft_same(var_name, "?"))
		var_value = ft_itoa(env->last_exit_status);
	else
		var_value = get_env_var_value(env, var_name);
	free(var_name);
	*i = end;
	return (var_value);
}

static char	*process_dollar_in_quote(t_env *env, char *content, char *result,
		int *i)
{
	char	*temp;
	char	*var_value;
	char	*exit_status;
	int		len;

	len = ft_strlen_int(content);
	var_value = handle_dollar_var(env, content, i, len);
	if (var_value)
	{
		temp = ft_strjoin(result, var_value);
		exit_status = ft_itoa(env->last_exit_status);
		if (ft_same(var_value, exit_status))
		{
			free(exit_status);
			free(var_value);
		}
		else
		{
			free(exit_status);
		}
	}
	else
		temp = ft_strdup(result);
	return (temp);
}

static char	*process_double_quote_content(t_env *env, char *content,
		char *result, int *i)
{
	char	*temp;
	int		len;
	char	tmp[2];

	len = ft_strlen_int(content);
	tmp[0] = content[*i];
	tmp[1] = '\0';
	if (content[*i] == '$' && *i + 1 < len)
	{
		temp = process_dollar_in_quote(env, content, result, i);
	}
	else
	{
		temp = ft_strjoin(result, tmp);
		(*i)++;
	}
	return (temp);
}

char	*handle_double_quote(t_env *env, char *content)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (content[i])
	{
		temp = process_double_quote_content(env, content, result, &i);
		if (!temp)
		{
			free(result);
			return (NULL);
		}
		free(result);
		result = temp;
	}
	return (result);
}
