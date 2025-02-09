/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:34:41 by ebennace          #+#    #+#             */
/*   Updated: 2024/08/13 11:02:06 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_finish(char c)
{
	if (c == '\0')
		return (1);
	return (0);
}

int	is_not_finish(char c)
{
	if (c != '\0')
		return (1);
	return (0);
}

int	index_not_over_flow(char *line, int index)
{
	if (index < ft_strlen_int(line))
		return (1);
	return (0);
}

int	index_is_over_flow(char *line, int index)
{
	if (index >= ft_strlen_int(line))
		return (1);
	return (0);
}
