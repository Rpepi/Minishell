/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:55:05 by pepi              #+#    #+#             */
/*   Updated: 2024/09/24 19:01:06 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_only_spaces_or_tabs(char *input)
{
	while (*input)
	{
		if (*input != ' ' && *input != '\t')
			return (1);
		input++;
	}
	return (0);
}

static int	print_syntax_error(char c)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
	return (1);
}

static int	check_next_token(char *input, int *i)
{
	while (input[*i] == ' ')
	{
		blank_escape(input, i);
		if (input[*i] == '>' || input[*i] == '<' || input[*i] == '|')
		{
			return (print_syntax_error(input[*i]));
		}
	}
	return (0);
}

int	check_consecutive_redir(char *input)
{
	int	i;

	if (!input)
		return (0);
	i = 0;
	while (input[i])
	{
		if ((input[i] == '>' || input[i] == '<' || input[i] == '|'))
		{
			i++;
			if (check_next_token(input, &i))
				return (1);
		}
		i++;
	}
	return (0);
}
