/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:42:05 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 10:25:32 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	create_pipe(int **pipes, int index)
{
	pipes[index] = malloc(2 * sizeof(int));
	if (!pipes[index])
	{
		perror("minishell: malloc");
		return (-1);
	}
	if (pipe(pipes[index]) == -1)
	{
		free(pipes[index]);
		perror("minishell: pipe");
		return (-1);
	}
	return (0);
}

int	**init_pipes(t_env *env, int nb_cmds)
{
	int	**pipes;
	int	i;

	if (nb_cmds <= 1)
		return (NULL);
	pipes = malloc((nb_cmds - 1) * sizeof(int *));
	if (!pipes)
	{
		perror("minishell: malloc");
		quit_program(env);
	}
	i = 0;
	while (i < nb_cmds - 1)
	{
		if (create_pipe(pipes, i) == -1)
		{
			cleanup_pipes(pipes, i);
			quit_program(env);
		}
		i++;
	}
	return (pipes);
}

int	handle_input_redirection(t_env *env, t_token *token, int index)
{
	if (!has_redir(token, "<") && !has_redir(token, "<<") && index != 0)
		return (dup2(env->pipes[index - 1][0], STDIN_FILENO));
	return (0);
}

static int	handle_output_redirection(t_env *env, t_token *token, int index)
{
	if (!has_redir(token, ">") && !has_redir(token, ">>")
		&& index != env->nb_cmd - 1)
		return (dup2(env->pipes[index][1], STDOUT_FILENO));
	return (0);
}

int	change_fd_pipes(t_env *env, t_token *token, int index)
{
	if (open_files(token, env))
		return (0);
	if (handle_input_redirection(env, token, index) == -1)
		return (0);
	if (handle_output_redirection(env, token, index) == -1)
		return (0);
	return (1);
}
