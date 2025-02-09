/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:28:15 by rpepi             #+#    #+#             */
/*   Updated: 2023/11/16 14:11:40 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				neg;
	int				i;
	unsigned long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || ((9 <= str[i]) && (str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		if (num > 9223372036854775807 && neg == -1)
			return (0);
		if (num > 9223372036854775807 && neg == 1)
			return (-1);
		i++;
	}
	return (num * neg);
}
