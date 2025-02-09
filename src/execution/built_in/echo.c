/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:44:50 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/23 22:07:07 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

static int	is_valid_n_option(const char *str)
{
	if (*str != '-')
		return (0);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

static void	print_echo_args(t_arg *actual_arg, int print_newline)
{
	int	first;

	first = 1;
	while (actual_arg)
	{
		if (!first)
			write(STDOUT_FILENO, " ", 1);
		write(STDOUT_FILENO, actual_arg->content,
			ft_strlen(actual_arg->content));
		first = 0;
		actual_arg = actual_arg->next;
	}
	if (print_newline)
		write(STDOUT_FILENO, "\n", 1);
}

int	exec_echo(t_cmd *cmd)
{
	t_arg	*actual_arg;
	int		print_newline;

	if (!cmd->first_arg)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	actual_arg = cmd->first_arg;
	print_newline = 1;
	while (actual_arg && is_valid_n_option(actual_arg->content))
	{
		print_newline = 0;
		actual_arg = actual_arg->next;
	}
	print_echo_args(actual_arg, print_newline);
	return (0);
}
