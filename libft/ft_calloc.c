/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:37 by pepi              #+#    #+#             */
/*   Updated: 2023/10/23 11:07:28 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;

	pointer = (char *)malloc(count * size);
	if (pointer == 0)
		return (0);
	ft_bzero(pointer, count * size);
	return (pointer);
}
