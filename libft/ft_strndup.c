/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:33:05 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/05/30 09:33:06 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i < n)
	{
		if (!(d = (char*)malloc(sizeof(*s) * i + 1)))
			return (NULL);
	}
	else
	{
		if (!(d = (char*)malloc(sizeof(*s) * n + 1)))
			return (NULL);
	}
	i = 0;
	while (s[i] != '\0' && n--)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
