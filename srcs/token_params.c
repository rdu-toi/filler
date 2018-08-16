/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:35:13 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/08/16 14:35:16 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_params(t_token *t, int i, int j, int first)
{
	while (i < t->ty)
	{
		j = 0;
		while (j < t->tx)
		{
			if (t->t[i][j] == '*' && !first)
			{
				t->top[0] = i;
				first = 1;
			}
			if (t->t[i][j] == '*' && t->bottom[0] < i)
				t->bottom[0] = i;
			if (t->t[i][j] == '*' && t->top[1] > j)
				t->top[1] = j;
			if (t->t[i][j] == '*' && t->bottom[1] < j)
				t->bottom[1] = j;
			j++;
		}
		i++;
	}
}

void	token_params(t_token *t)
{
	int		i;
	int		j;
	int		first;

	i = 0;
	j = 0;
	first = 0;
	t->top[0] = 0;
	t->top[1] = t->tx;
	t->bottom[0] = 0;
	t->bottom[1] = 0;
	find_params(t, i, j, first);
}
