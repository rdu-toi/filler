/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:17:44 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/05/22 21:17:45 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (dst[j] != '\0' && j < dstsize)
		j += 1;
	i = j;
	while (src[j - i] != '\0' && (j + 1) < dstsize)
	{
		dst[j] = src[j - i];
		j += 1;
	}
	if (i < dstsize)
		dst[j] = '\0';
	return (i + ft_strlen(src));
}
