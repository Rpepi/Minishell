/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:23:05 by rpepi             #+#    #+#             */
/*   Updated: 2024/01/04 16:23:24 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *input, int n)
/*
** duplicates n characters from input into output
** output is a allocated string
*/
{
	char	*output;
	int		len;
	int		i;

	i = 0;
	len = n;
	output = malloc(len + 1);
	if (!output)
		return (NULL);
	while (input && input[i] != '\0' && i < n)
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
