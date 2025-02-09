/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:18:12 by pepi              #+#    #+#             */
/*   Updated: 2024/08/28 13:58:44 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	double_quotes_detection(char *line, int *index)
{
	*index = *index + 1;
	while (line[*index])
	{
		if (is_double_quote(line[*index]))
			return ;
		*index = *index + 1;
	}
}

static void	single_quotes_detection(char *line, int *index)
{
	*index = *index + 1;
	while (line[*index])
	{
		if (is_single_quote(line[*index]))
			return ;
		*index = *index + 1;
	}
}

void	string_detection(char *line, int *i)
{
	while (line[*i])
	{
		if (is_delimiter(line, *i))
		{
			*i = *i - 1;
			return ;
		}
		if (is_double_quote(line[*i]))
		{
			double_quotes_detection(line, i);
			return ;
		}
		if (is_single_quote(line[*i]))
		{
			single_quotes_detection(line, i);
			return ;
		}
		*i = *i + 1;
	}
}

void	file_detection(t_env *env, char *line, int *i)
{
	(void)env;
	while (line[*i])
	{
		if (is_delimiter(line, *i))
		{
			*i -= 1;
		}
		if (is_double_quote(line[*i]))
		{
			double_quotes_detection(line, i);
		}
		if (is_single_quote(line[*i]))
		{
			single_quotes_detection(line, i);
		}
		(*i)++;
	}
}

int	blank_detection(char *line, int index)
{
	while (line[index] && is_blank(line[index]))
	{
		index++;
	}
	return (index);
}
