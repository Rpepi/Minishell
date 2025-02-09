/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:30:56 by pepi              #+#    #+#             */
/*   Updated: 2024/09/20 11:32:27 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*get_name_without_dollar(char *content)
{
	int		i;
	int		j;
	char	*name;

	i = 1;
	j = 0;
	name = (char *)malloc(sizeof(char) * ft_strlen_int(content));
	while (content[i] != '\0')
	{
		name[j] = content[i];
		i++;
		j++;
	}
	name[j] = '\0';
	return (name);
}

char	*get_quote_content(char *content, int start)
{
	int		end;
	char	*new_content;

	end = start;
	while (content[end] != '\0' && (content[end] != '\"'
			|| content[end] != '\''))
		end++;
	new_content = ft_malloc_substrcpy(content, start + 1, end - 3);
	return (new_content);
}

int	find_end_quote(char *content, int start)
{
	int		i;
	char	quote_type;

	i = start;
	quote_type = content[i];
	i++;
	while (content[i] != '\0' && content[i] != quote_type)
		i++;
	if (content[i] == quote_type)
		return (i);
	return (i);
}
