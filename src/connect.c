/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:45:04 by pepi              #+#    #+#             */
/*   Updated: 2024/08/13 11:45:47 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	connect_token(t_token *curr_token, t_token *next_token)
{
	curr_token->next = next_token;
	next_token->prev = curr_token;
}

void	connect_var(t_var *curr_var, t_var *next_var)
{
	curr_var->next = next_var;
	next_var->prev = curr_var;
}

void	connect_arg(t_arg *curr_arg, t_arg *next_arg)
{
	curr_arg->next = next_arg;
	next_arg->prev = curr_arg;
}

void	connect_new_var(t_var *prev_var, t_var *curr_var, t_var *next_var)
{
	if (!prev_var)
		curr_var->prev = NULL;
	else
	{
		curr_var->prev = prev_var;
		prev_var->next = curr_var;
	}
	if (!next_var)
		curr_var->next = NULL;
	else
	{
		curr_var->next = next_var;
		next_var->prev = curr_var;
	}
}
