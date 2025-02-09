/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:36:13 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/20 11:36:39 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	line_is_finish(char *line, int index)
{
	if (index >= ft_strlen_int(line) && is_finish(line[index]))
		return (1);
	return (0);
}

int	line_is_not_finish(char *line, int index)
{
	if (index < ft_strlen_int(line) && is_not_finish(line[index]))
		return (1);
	return (0);
}

int	line_is_empty(char	*line)
{
	if (ft_strlen_int(line) == 0)
		return (1);
	else
		return (0);
}

int	line_is_not_empty(char	*line)
{
	if (ft_strlen_int(line) > 0)
		return (1);
	return (0);
}
