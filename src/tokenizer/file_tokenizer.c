/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:04:35 by pepi              #+#    #+#             */
/*   Updated: 2024/11/06 11:55:24 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	find_string_start(t_env *env, char *line, int *index)
{
	while (!is_string(line, *index))
	{
		if (line[*index] == '\0')
		{
			ft_putstr_fd("Error: syntax", 2);
			env->error_in_parsing += 1;
			return (0);
		}
		(*index)++;
	}
	return (1);
}

static char	*process_file_content(t_env *env, char *line, int start, int end)
{
	char	*content;
	char	*new_content;
	char	*content_rest;

	(void)env;
	new_content = NULL;
	content = ft_malloc_substrcpy(line, start, end);
	content_rest = ft_strdup(content);
	new_content = check_arg(env, content);
	if (new_content)
	{
		free(content_rest);
		free(content);
		return (new_content);
	}
	free(content);
	return (content_rest);
}

static char	*extract_file_content(t_env *env, char *line, int *index)
{
	int	start;

	if (line[*index] == '\0')
		return (NULL);
	if (!find_string_start(env, line, index))
		return (NULL);
	start = *index;
	string_detection(line, index);
	return (process_file_content(env, line, start, *index));
}

void	find_next_file(t_env *env, t_redir *redir, char *line, int *index)
{
	char	*content;
	char	*new_content;

	new_content = NULL;
	content = extract_file_content(env, line, index);
	if (!content)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(content, 2);
		ft_putstr_fd(": ambiguous redirect\n", 2);
		env->error_in_parsing += 1;
		return ;
	}
	new_content = check_arg(env, content);
	if (!new_content)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(content, 2);
		ft_putstr_fd(": ambiguous redirect\n", 2);
		env->error_in_parsing += 1;
		return ;
	}
	free(new_content);
	redir->file_name = content;
}
