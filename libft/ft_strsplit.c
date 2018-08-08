/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:29:56 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/05/24 12:29:57 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcount(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			i = i + ft_strlenc(&s[i], c) - 1;
			j++;
		}
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	k;
	char	**arr;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	len = ft_strcount(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			arr[k++] = ft_strsub(s, i, ft_strlenc(&s[i], c));
			i += ft_strlenc(&s[i], c) - 1;
		}
		i++;
	}
	arr[k] = NULL;
	return (arr);
}
