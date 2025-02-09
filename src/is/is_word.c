/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:12:03 by vlibert           #+#    #+#             */
/*   Updated: 2024/09/20 13:07:19 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_word(char *word)
{
	int	len;

	len = ft_strlen(word);
	if (ft_isalnum(word[0]) && ft_isalnum(word[len - 1]))
		return (1);
	return (0);
}
