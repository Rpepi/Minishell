/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hereroc_dollar_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:17:24 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 14:42:09 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*join_and_free(char *s1, char *s2, int free_s2)
{
	char	*result;
	char	*temp;

	temp = s1;
	result = ft_strjoin(s1, s2);
	free(temp);
	if (free_s2)
		free(s2);
	return (result);
}

static char	*handle_heredoc_dollar(char *result, t_env *env, char *line, int *i)
{
	char	*expanded;
	int		len;

	len = ft_strlen(line);
	if (line[*i] == '$' && *i + 1 < len)
	{
		expanded = ft_strdup(handle_dollar_var(env, line, i, len));
		if (expanded)
		{
			result = join_and_free(result, expanded, 1);
		}
	}
	return (result);
}

char	*expand_heredoc_line(char *line, t_env *env)
{
	int		i;
	char	*result;
	char	curr[2];

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	curr[1] = '\0';
	while (i < ft_strlen_int(line))
	{
		if (line[i] == '$' && i + 1 < ft_strlen_int(line))
		{
			result = handle_heredoc_dollar(result, env, line, &i);
		}
		else
		{
			curr[0] = line[i++];
			result = join_and_free(result, curr, 0);
		}
		if (!result)
			return (NULL);
	}
	return (result);
}
