/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 00:26:54 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/05/26 00:26:57 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	sub = NULL;
	if (!s)
		return (NULL);
	if (!(sub = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len-- && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
