/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 00:14:13 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/05/29 00:14:14 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		if ((unsigned char)c == ((unsigned const char *)src)[i])
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
