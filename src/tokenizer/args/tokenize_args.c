/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:42:01 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/26 14:54:22 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	find_type_arg(char *content)
{
	int	i;

	i = 0;
	if (content == NULL)
		return (0);
	blank_escape(content, &i);
	if (is_flag_arg(content, i))
		return (9);
	else if (is_file(content, i))
		return (12);
	else if (is_string(content, i))
		return (2);
	else if (is_redir(content, i))
		return (13);
	return (0);
}

int	find_end_arg(char *line, int index)
{
	int		i;
	char	quote;

	i = index;
	quote = 0;
	while (line[i] != '\0')
	{
		if (quote == 0 && (line[i] == '\'' || line[i] == '"'))
			quote = line[i];
		else if (quote != 0 && line[i] == quote)
			quote = 0;
		else if (quote == 0 && line[i] == ' ')
			break ;
		i++;
	}
	return (i - 1);
}

void	tokenize_arg(t_env *env, t_cmd *cmd, char *line, int *index)
{
	int		type;
	char	*content;
	char	*new_content;
	t_arg	*arg;
	int		start;

	(void)env;
	new_content = NULL;
	start = *index;
	*index = find_end_arg(line, *index);
	content = ft_malloc_substrcpy(line, start, *index);
	new_content = check_arg(env, content);
	if (content)
		free(content);
	type = find_type_arg(new_content);
	if (type == 0)
	{
		free(new_content);
		return ;
	}
	arg = init_arg(new_content, type);
	if (arg)
		add_arg_list(cmd, arg);
}

t_arg	*init_arg(char *content, int id)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->id = id;
	arg->content = content;
	arg->prev = NULL;
	arg->next = NULL;
	return (arg);
}
