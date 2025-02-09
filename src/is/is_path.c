/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:56:23 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/20 11:37:18 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_path(const char *path)
{
	return ((path[0] == '/' && path[1]) || ((path[0] == '.' && path[1] == '/')
			&& path[2]));
}

int	is_absolute_path(const char *path)
{
	return (path[0] == '/' && path[1]);
}

int	is_relative_path(const char *path)
{
	return (((path[0] == '.' && path[1] == '/') && path[2]));
}
