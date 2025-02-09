/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:47:57 by pepi              #+#    #+#             */
/*   Updated: 2024/09/16 11:51:23 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	col_count(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_malloc_strcpy(char *origin)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen_int(origin) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (origin[i])
	{
		str[i] = origin[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_malloc_strcpy_array(char **origin)
{
	size_t	i;
	size_t	len;
	char	**array;

	if (!origin)
		return (NULL);
	len = col_count(origin);
	array = malloc(sizeof(char *) * (len + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (origin[i])
	{
		array[i] = ft_malloc_strcpy(origin[i]);
		if (!array[i])
		{
			while (i > 0)
				free(array[--i]);
			free(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	*ft_malloc_substrcpy(char *origin, int start, int end)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = (end - start) + 1;
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = origin[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
