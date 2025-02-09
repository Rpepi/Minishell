/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:01:44 by pepi              #+#    #+#             */
/*   Updated: 2024/09/25 11:40:39 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	str_compare(const char *a, const char *b)
{
	return (strcmp(a, b));
}

static int	validate_name(char *str)
{
	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (0);
	}
	return (1);
}

static int	validate_chars(char *str, int *index)
{
	while (str[*index] != '=' && str[*index] != '\0')
	{
		if (!ft_isalnum(str[*index]) && str[*index] != '_')
		{
			write(2, "minishell: export: `", 16);
			ft_putstr_fd(str, 2);
			write(2, "': not a valid identifier\n", 27);
			return (0);
		}
		*index = *index + 1;
	}
	return (1);
}

static char	*extract_name(char *str, int *index, t_arg *arg)
{
	char	*name;

	name = NULL;
	if (str[*index] == '=')
	{
		*index = *index - 1;
		name = ft_malloc_substrcpy(str, 0, *index);
		*index = *index + 2;
		return (name);
	}
	else if (arg->next && check_is_value(arg->next->content))
	{
		write(2, "bash: export: `", 16);
		ft_putstr_fd(arg->next->content, 2);
		write(2, "': not a valid identifier\n", 27);
	}
	return (NULL);
}

char	*get_name_arg(t_arg *arg, int *index)
{
	char	*str;

	str = arg->content;
	if (!validate_name(str) || !validate_chars(str, index))
		return (NULL);
	return (extract_name(str, index, arg));
}
