/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:53:04 by rpepi             #+#    #+#             */
/*   Updated: 2024/03/07 17:57:36 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_after_percent(const char format, va_list args)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_printchar(va_arg(args, int));
	if (format == 's')
		length += ft_printstr(va_arg(args, char *));
	if (format == 'd' || format == 'i')
		length += ft_printnbr(va_arg(args, int));
	if (format == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long int));
	if (format == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		length += ft_print_hexa(va_arg(args, unsigned int), format);
	if (format == '%')
		length += ft_printpercent();
	return (length);
}

int	ft_printf(const char	*format, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length += ft_after_percent(format[i + 1], args);
			i++;
		}
		else
			length += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}
