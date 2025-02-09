/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:54:14 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/26 10:21:52 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_in_quotes_index(const char *str, int index)
{
	int		i;
	char	quote_type;
	int		in_quotes;

	i = 0;
	in_quotes = 0;
	quote_type = 0;
	while (i < index && str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && !in_quotes)
		{
			in_quotes = 1;
			quote_type = str[i];
		}
		else if (str[i] == quote_type && in_quotes)
		{
			in_quotes = 0;
			quote_type = 0;
		}
		i++;
	}
	return (in_quotes);
}

int	check_invalid_chars(char *input)
{
	while (*input)
	{
		if (((*input == '&' && *(input + 1) == '&') || *input == '\\'
				|| *input == ';' || (*input == '|' && *(input + 1) == '|'))
			&& (!is_in_quotes_index(input, *input)))
		{
			ft_putstr_fd("Error: '", 2);
			ft_putchar_fd(*input, 2);
			ft_putstr_fd("': not handled", 2);
			ft_putstr_fd("\n", 2);
			return (0);
		}
		input++;
	}
	return (1);
}

int	check_unclosed_quotes(char *input)
{
	int	single_quote_open;
	int	double_quote_open;

	single_quote_open = 0;
	double_quote_open = 0;
	while (*input)
	{
		if (*input == '\'')
			single_quote_open = !single_quote_open;
		if (*input == '"')
			double_quote_open = !double_quote_open;
		input++;
	}
	if (single_quote_open || double_quote_open)
	{
		ft_putstr_fd("Error: unclosed quotes\n", 2);
		return (0);
	}
	return (1);
}

int	check_input(t_env *env, char *input)
{
	if (!check_unclosed_quotes(input) || (!check_invalid_chars(input))
		|| !check_only_spaces_or_tabs(input) || check_redir_error(input)
		|| check_consecutive_redir(input))
	{
		env->last_exit_status = 1;
		return (0);
	}
	return (1);
}
