/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:17:35 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 11:54:36 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cleanup_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	if (!pipes)
		return ;
	while (i < count)
	{
		if (pipes[i])
		{
			if (pipes[i][0] >= 0)
				close(pipes[i][0]);
			if (pipes[i][1] >= 0)
				close(pipes[i][1]);
			free(pipes[i]);
			pipes[i] = NULL;
		}
		i++;
	}
	if (pipes)
		free(pipes);
}

void	close_unused_pipes(t_env *env, int index)
{
	int	i;

	i = 0;
	while (i < env->nb_cmd - 1)
	{
		if (i != index - 1)
			close(env->pipes[i][0]);
		if (i != index)
			close(env->pipes[i][1]);
		i++;
	}
}
