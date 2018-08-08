/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:48:50 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/07/09 21:55:24 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_index(const char *str, char c)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			break ;
		index++;
	}
	return (index);
}
