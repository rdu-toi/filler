/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:48:48 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/06/02 21:48:49 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	nbr;
	int		flag;
	int		len;
	char	*str;

	nbr = n;
	flag = 0;
	len = ft_nbrlen((int)nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	len--;
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
		flag = 1;
	}
	while (len >= flag)
	{
		str[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
