/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:58:48 by vlibert           #+#    #+#             */
/*   Updated: 2024/11/06 16:02:36 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	quit_program(t_env *env)
{
	env->last_exit_status = 1;
	free_tokens(env);
	free_env(env);
	exit(0);
}
