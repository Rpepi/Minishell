/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:49:30 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/20 11:24:30 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_strjoin_free_first(char *s1, char *s2)
{
	char	*complete;

	complete = ft_strjoin(s1, s2);
	free(s1);
	s1 = NULL;
	return (complete);
}

char	*cmd_list_to_string(t_cmd *cmd)
{
	t_arg	*arg;
	char	*complete;

	if (!(cmd_have_args(cmd)))
		return (NULL);
	arg = cmd->first_arg;
	if (arg->content == NULL)
		return (NULL);
	complete = ft_malloc_strcpy(arg->content);
	arg = arg->next;
	while (arg)
	{
		complete = ft_strjoin_free_first(complete, arg->content);
		arg = arg->next;
	}
	return (complete);
}
