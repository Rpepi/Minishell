/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:50:59 by pepi              #+#    #+#             */
/*   Updated: 2023/11/16 14:10:56 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chr1;
	unsigned char	*chr2;

	chr1 = (unsigned char *)s1;
	chr2 = (unsigned char *)s2;
	while (n--)
	{
		if (*chr1 != *chr2)
			return (*chr1 - *chr2);
		chr1++;
		chr2++;
	}
	return (0);
}
