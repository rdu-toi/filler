/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:17:00 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/05/24 09:17:01 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str;

	str = NULL;
	if (size)
	{
		if (!(str = (unsigned char *)malloc(size)))
			return (NULL);
		str[size] = 0;
		while (size)
			str[--size] = 0;
	}
	return ((void *)str);
}
