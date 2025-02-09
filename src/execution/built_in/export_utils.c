/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:43:41 by pepi              #+#    #+#             */
/*   Updated: 2024/09/23 12:50:16 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

void	swap_vars(t_var **a, t_var **b)
{
	t_var	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	count_vars(t_env *env)
{
	int		count;
	t_var	*current;

	count = 0;
	current = env->first_var;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static void	fill_var_array(t_env *env, t_var **var_array, int count)
{
	t_var	*current;
	int		i;

	current = env->first_var;
	i = 0;
	while (i < count)
	{
		var_array[i] = current;
		current = current->next;
		i++;
	}
}

static void	sort_var_array(t_var **var_array, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (str_compare(var_array[j]->name, var_array[j + 1]->name) > 0)
			{
				swap_vars(&var_array[j], &var_array[j + 1]);
			}
			j++;
		}
		i++;
	}
}

void	print_exported_vars(t_env *env)
{
	int		count;
	t_var	**var_array;
	int		i;

	count = count_vars(env);
	var_array = malloc(count * sizeof(t_var *));
	if (!var_array)
	{
		ft_putstr_fd("Erreur d'allocation mémoire\n", 2);
		return ;
	}
	fill_var_array(env, var_array, count);
	sort_var_array(var_array, count);
	i = 0;
	while (i < count)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(var_array[i]->name, 1);
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(var_array[i]->value, 1);
		ft_putstr_fd("\"\n", 1);
		i++;
	}
	free(var_array);
}
