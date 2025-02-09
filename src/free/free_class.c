/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_class.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:03:37 by rpepi             #+#    #+#             */
/*   Updated: 2024/11/06 12:47:12 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_cmd(t_cmd *cmd)
{
	t_arg	*arg;
	t_arg	*arg_tmp;

	arg = NULL;
	arg_tmp = NULL;
	if (cmd->content)
		free(cmd->content);
	if (cmd->arg)
		free(cmd->arg);
	if (cmd->args)
		ft_free_dtab(cmd->args);
	if (cmd->bin)
		free(cmd->bin);
	if (cmd->first_arg)
		arg = cmd->first_arg;
	while (arg)
	{
		arg_tmp = arg;
		arg = arg->next;
		if (arg_tmp && arg_tmp->content)
			free(arg_tmp->content);
		free(arg_tmp);
	}
	free(cmd);
}

void	free_word(t_word *word)
{
	if (word && word->content)
		free(word->content);
}

void	free_file(t_file *file)
{
	if (file && file->name)
		free(file->name);
}

void	free_redir(t_redir *redir)
{
	if (redir)
	{
		if (redir->limiter)
		{
			free(redir->limiter);
			redir->limiter = NULL;
		}
		if (redir->content)
		{
			free(redir->content);
			redir->content = NULL;
		}
		if (redir->file_name)
		{
			free(redir->file_name);
			redir->file_name = NULL;
		}
		free(redir);
	}
}
