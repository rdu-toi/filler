/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:50:02 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/08/17 11:50:03 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	placementX1(t_map *m, t_token *t, t_player *p, int mi, int mj, int i, int j)
{
	int		w;
	int		flag;

	flag = 0;
	w = 0;
	while (t->top[0] + i <= t->bottom[0])
	{
		j = 0;
		while (t->top[1] + j <= t->bottom[1])
		{
			if ((m->m[mi + i][mj + j] == p->p2 && t->t[t->top[0] + i][t->top[1] + j] == '*') || w > 1)
				flag = 1;
			if (!flag && t->t[t->top[0] + i][t->top[1] + j] == '*' && m->m[mi + i][mj + j] == p->p1)
				w++;
			j++;
		}
		if (flag)
			break;
		i++;
	}
	if (w == 1 && !flag)
	{
		p->pos[0] = mi - t->top[0];
		p->pos[1] = mj - t->top[1];
	}
}

void	placementX(t_map *m, t_token *t, t_player *p, int mi, int mj, int i, int j)
{
	int		flag;

	flag = 0;
	while (mi >= 0)
	{
		mj = m->mx - t->bottom[1] - t->top[1] - 1;
		while (mj >= 0)
		{
			placementX1(m, t, p, mi, mj, i, j);
			if (p->pos[0] != 0 && p->pos[1] != 0)
				return ;
			mj--;
		}
		mi--;
	}
}

void	placementO1(t_map *m, t_token *t, t_player *p, int mi, int mj, int i, int j)
{
	int		w;
	int		flag;

	flag = 0;
	w = 0;
	while (t->top[0] + i <= t->bottom[0])
	{
		j = 0;
		while (t->top[1] + j <= t->bottom[1])
		{
			if ((m->m[mi + i][mj + j] == p->p2 && t->t[t->top[0] + i][t->top[1] + j] == '*') || w > 1)
				flag = 1;
			if (!flag && t->t[t->top[0] + i][t->top[1] + j] == '*' && m->m[mi + i][mj + j] == p->p1)
				w++;
			j++;
		}
		if (flag)
			break;
		i++;
	}
	if (w == 1 && !flag)
	{
		p->pos[0] = mi - t->top[0];
		p->pos[1] = mj - t->top[1];
	}
}

void	placementO(t_map *m, t_token *t, t_player *p, int mi, int mj, int i, int j)
{
	int		flag;

	flag = 0;
	while (mi + t->bottom[0] - t->top[0] < m->my)
	{
		mj = 0;
		while (mj + t->bottom[1] - t->top[1] < m->mx)
		{
			placementO1(m, t, p, mi, mj, i, j);
			if (p->pos[0] != 0 && p->pos[1] != 0)
				return ;
			mj++;
		}
		mi++;
	}
}

void	token_placement(t_map *m, t_token *t, t_player *p)
{
	int		mi;
	int		mj;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (p->p1 == 'O')
	{
		mi = 0;
		mj = 0;
		placementO(m, t, p, mi, mj, i, j);
	}
	else if (p->p1 == 'X')
	{
		mi = m->my - t->bottom[0] - t->top[0] - 1;
		mj = m->mx - t->bottom[1] - t->top[1] - 1;
		placementX(m, t, p, mi, mj, i, j);
	}
}
