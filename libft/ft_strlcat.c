/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:15:12 by pepi              #+#    #+#             */
/*   Updated: 2023/11/16 14:10:31 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	i;
	size_t	len_src;

	if (!dest && size == 0 && src)
		return (ft_strlen(src));
	if (size == 0)
		return (ft_strlen(src));
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size < len_dest)
		len_src += size;
	else
		len_src += len_dest;
	i = 0;
	while (src[i] != '\0' && (len_dest + i) < size - 1)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_src);
}
