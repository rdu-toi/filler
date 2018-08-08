/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlinesplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 11:49:11 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/06/29 11:49:15 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split(char const *s, char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\n')
		{
			arr[j] = ft_strsub(s, i, ft_strlenc(&s[i], '\n'));
			i = i + ft_strlenc(&s[i], '\n');
			j++;
		}
		else if (s[i] == '\n')
		{
			arr[j] = ft_strsub(s, 0, 0);
			j++;
		}
		i++;
	}
	return (j);
}

char		**ft_strlinesplit(char const *s)
{
	int		j;
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * ft_linecount(s) + 1);
	if (!arr)
		return (NULL);
	j = ft_split(s, arr);
	if (!j)
		arr[0] = ft_strsub(s, 0, 0);
	arr[j] = "\0";
	return (arr);
}
