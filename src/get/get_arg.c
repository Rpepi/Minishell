/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:00:07 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 16:45:29 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
 * Function that retruns the number of arguments of a cmd
 * From the first arg of a cmd
 */
static int	get_nb_args(t_arg *arg)
{
	t_arg	*actual_arg;
	int		len;

	actual_arg = arg;
	len = 0;
	while (actual_arg)
	{
		len++;
		actual_arg = actual_arg->next;
	}
	return (len);
}

/*
 * Function that returns the next arguments for a command
 * in an array
 */
char	**get_next_args_in_array(t_cmd *cmd)
{
	t_arg	*arg;
	char	**array;
	int		len;
	int		i;

	i = 0;
	arg = cmd->first_arg;
	len = get_nb_args(arg);
	array = malloc((len + 2) * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < (len + 1))
	{
		if (i == 0)
			array[i] = ft_strdup(cmd->content);
		else if (arg)
		{
			array[i] = ft_strdup(arg->content);
			arg = arg->next;
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
