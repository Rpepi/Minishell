/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:37:35 by rpepi             #+#    #+#             */
/*   Updated: 2023/12/08 14:43:07 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenght_hexa(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hexa(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hexa(num / 16, format);
		ft_put_hexa(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hexa(unsigned int num, const char format)
{
	int	length;

	length = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		length += 1;
	}
	else
	{
		ft_put_hexa(num, format);
		length += ft_lenght_hexa(num);
	}
	return (length);
}
