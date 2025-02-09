/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:18:38 by ebennace          #+#    #+#             */
/*   Updated: 2024/08/13 11:02:22 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	same_name(char *first, char *second)
{
	if (ft_strncmp(first, second, ft_strlen_int(second)))
	{
		return (1);
	}
	return (0);
}
