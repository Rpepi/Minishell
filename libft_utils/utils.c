/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpepi <rpepi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:35:09 by pepi              #+#    #+#             */
/*   Updated: 2024/08/26 14:50:29 by rpepi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_inter(char *s1, char *s2, char c)
{
	char	*cont;
	int		i;
	int		y;

	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1);
	y = ft_strlen(s2);
	cont = malloc((i + y + 2) * sizeof(char));
	i = 0;
	y = 0;
	while (s1[i])
	{
		cont[i] = s1[i];
		i++;
	}
	cont[i] = c;
	while (s2[y])
	{
		cont[i + y + 1] = s2[y];
		++y;
	}
	cont[i + y + 1] = '\0';
	return (cont);
}

static char	*ft_strjoin_inter_str_code(char	*s1, char	*s2,
		char *content, int i)
{
	char	*str;
	int		j;
	int		k;
	int		l;

	j = 0;
	k = 0;
	l = 0;
	str = malloc(sizeof(char) * (ft_strlen_int(s1)
				+ ft_strlen_int(s2) + ft_strlen_int(content) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[l++] = s1[i++];
	while (content[j])
		str[l++] = content[i++];
	while (s2[k])
		str[l++] = s2[k++];
	str[l] = '\0';
	return (str);
}

char	*ft_strjoin_inter_str(char *s1, char *s2, char *content)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strjoin_inter_str_code(s1, s2, content, i);
	return (str);
}

int	ft_ismaj(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_letter(char c)
{
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	return (0);
}
