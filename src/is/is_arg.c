/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:58:36 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/16 12:02:09 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_arg_variable(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_VARIABLE)
		return (1);
	return (0);
}

int	is_arg_flags(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_FLAGS)
		return (1);
	return (0);
}

int	is_arg_blank(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_BLANK)
		return (1);
	return (0);
}

int	is_flag(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] != '-')
		return (0);
	i++;
	while (str[i] && str[i] != ' ')
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}
