/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:20:09 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/08/11 21:20:10 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

void	test2(char **str)
{
	printf("%s\n", *str);
	if (!ft_strncmp(*str, "oll", 3))
		*str = "Mate!";
}

void	test(char **str)
{
	printf("%s\n", *str);
	if (!ft_strncmp(*str, "Hel", 3))
		*str = ft_strrev(*str);
	//char	*str2 = " World";
	//*str = "World";
	test2(str);
}

int		main(void)
{
	char	*str;

	get_next_line(0, &str);
	test(&str);
	printf("%s\n", str);
}
