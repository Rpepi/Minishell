/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:59:15 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/20 11:39:01 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
 * Function that retruns the number of arguments of a cmd
 * From the first arg of a cmd
 */
static int	get_nb_var(t_var *var)
{
	t_var	*actual_var;
	int		len;

	actual_var = var;
	len = 0;
	while (actual_var)
	{
		len++;
		actual_var = actual_var->next;
	}
	return (len);
}

/*
** Function that free if malloc error in get_env_vars
*/
void	free_get_env_vars(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
	return ;
}

static char	*create_env_string(t_var *var)
{
	char	*temp;
	char	*result;

	if (var->value)
	{
		temp = ft_strjoin(var->name, "=");
		if (!temp)
			return (NULL);
		result = ft_strjoin(temp, var->value);
		free(temp);
	}
	else
		result = ft_strjoin(var->name, "=");
	return (result);
}

/*
 * Function that returns the vars of env in a array for a command
 * in an array
 */
char	**get_env_vars(t_var *var)
{
	t_var	*following;
	char	**array;
	int		len;
	int		i;

	i = 0;
	following = var;
	len = get_nb_var(var);
	array = malloc((len + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < len)
	{
		array[i] = create_env_string(following);
		if (!array[i])
			return (free_get_env_vars(array), NULL);
		following = following->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
