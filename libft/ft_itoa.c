/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:37:46 by rpepi             #+#    #+#             */
/*   Updated: 2024/09/20 11:23:49 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*dest;
	long	nb;

	nb = n;
	i = ft_nbrlen(nb);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	dest[i--] = '\0';
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		dest[0] = '0';
	while (nb > 0)
	{
		dest[i--] = '0' + (nb % 10);
		nb /= 10;
	}
	return (dest);
}
