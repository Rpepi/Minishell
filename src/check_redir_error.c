/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:51:41 by pepi              #+#    #+#             */
/*   Updated: 2024/09/24 18:55:02 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	print_redir_error(char *input, int i)
{
	if (input[i] == '\0')
	{
		ft_putstr_fd("minishell: syntax error near ", 2);
		ft_putstr_fd("token `newline'\n", 2);
	}
	else
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putchar_fd(input[i], 2);
		if (input[i + 1] && input[i] == input[i + 1])
			ft_putchar_fd(input[i + 1], 2);
		ft_putstr_fd("'\n", 2);
	}
	return (1);
}

static int	check_redirection(char *input, int *i)
{
	int	j;
	int	count;

	j = *i;
	count = 0;
	while (input[j] == input[*i] && count < 2)
	{
		count++;
		j++;
	}
	if (count > 2)
		return (print_redir_error(input, *i));
	while (input[j] && input[j] == ' ')
		j++;
	if (input[j] == '<' || input[j] == '>' || input[j] == '|'
		|| input[j] == '\0')
		return (print_redir_error(input, j));
	*i = j - 1;
	return (0);
}

static int	check_pipe(char *input, int i)
{
	int	j;

	j = i + 1;
	if (input[j] == '|')
		return (print_redir_error(input, i));
	if (i == 0 || input[i + 1] == '\0')
		return (print_redir_error(input, i));
	while (input[j] && input[j] == ' ')
		j++;
	if (input[j] == '|' || input[j] == '<' || input[j] == '>'
		|| input[j] == '\0')
		return (print_redir_error(input, j));
	return (0);
}

int	check_redir_error(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '<' || input[i] == '>')
		{
			if (check_redirection(input, &i))
				return (1);
		}
		else if (input[i] == '|')
		{
			if (check_pipe(input, i))
				return (1);
		}
		i++;
	}
	if (i > 0 && (input[i - 1] == '<' || input[i - 1] == '>'
			|| input[i - 1] == '|'))
		return (print_redir_error(input, i - 1));
	return (0);
}
