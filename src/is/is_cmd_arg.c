/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:30:32 by ebennace          #+#    #+#             */
/*   Updated: 2024/09/20 12:47:22 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_argument(char *line, int i)
{
	if (!(is_separator(line, i)) && !(is_blank(line[i])))
		return (1);
	return (0);
}

int	is_flag_arg(char *line, int i)
{
	int	len;

	len = ft_strlen(line);
	if (i + 2 >= len)
		return (0);
	if (line[i] == '-' && line[i + 1] == 'n' && line[i + 2] == ' ')
		return (1);
	return (0);
}
