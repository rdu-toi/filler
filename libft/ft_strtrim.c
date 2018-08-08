/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 11:19:20 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/05/25 11:19:22 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] && ft_iswspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	j = ft_strlen(s) - 1;
	while (ft_iswspace(s[j]) && j >= 1)
		j--;
	if (!(str = ft_strnew(j - i + 1)))
		return (NULL);
	ft_strncpy(str, &s[i], (j - i + 1));
	return (str);
}
