/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:50:58 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/27 00:01:11 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parsing(t_env *env, char *input)
{
	int	index;

	index = 0;
	while (index < ft_strlen_int(input))
	{
		if (is_redir(input, index))
		{
			class_redir(env, input, &index);
		}
		else if (is_string(input, index))
		{
			class_string(env, input, &index);
		}
		index++;
	}
}

static void	reset_counter_error(t_env *env)
{
	env->error_in_parsing = 0;
}

void	execute_line(t_env *env, char *input)
{
	parsing(env, input);
	if (env->error_in_parsing > 0 || !check_parsing(env))
	{
		reset_counter_error(env);
		free_tokens(env);
		return ;
	}
	check_inversion_redir(env);
	check_token_word(env);
	if (!check_word_without_cmd(env) || !check_token_cmd_next_pipe(env))
	{
		free_tokens(env);
		return ;
	}
	execution(env);
	free_tokens(env);
}
