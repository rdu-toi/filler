/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:51:04 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/07/10 00:33:46 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_index(const char *str, char c)
{
	char	*fresh;
	int		i;

	i = 0;
	fresh = NULL;
	if (ft_is_char(str, c))
	{
		i = ft_char_index(str, c);
		fresh = ft_strndup(str, i);
	}
	return (fresh);
}
