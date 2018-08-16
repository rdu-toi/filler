/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:03:27 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/08/07 12:03:27 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	error(int x)
{
	ft_putstr_fd("Error ", 2);
	ft_putnbr_fd(x, 2);
	write(2, ", ", 2);
}

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
			{
				flag = 1;
				break;
			}
			mj--;
		}
		if (flag)
			break;
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
			{
				flag = 1;
				break;
			}
			mj++;
		}
		if (flag)
			break;
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

// void	find_params(t_token *t, int i, int j, int first)
// {
// 	while (i < t->ty)
// 	{
// 		j = 0;
// 		while (j < t->tx)
// 		{
// 			if (t->t[i][j] == '*' && !first)
// 			{
// 				t->top[0] = i;
// 				first = 1;
// 			}
// 			if (t->t[i][j] == '*' && t->bottom[0] < i)
// 				t->bottom[0] = i;
// 			if (t->t[i][j] == '*' && t->top[1] > j)
// 				t->top[1] = j;
// 			if (t->t[i][j] == '*' && t->bottom[1] < j)
// 				t->bottom[1] = j;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	token_params(t_token *t)
// {
// 	int		i;
// 	int		j;
// 	int		first;

// 	i = 0;
// 	j = 0;
// 	first = 0;
// 	t->top[0] = 0;
// 	t->top[1] = t->tx;
// 	t->bottom[0] = 0;
// 	t->bottom[1] = 0;
// 	find_params(t, i, j, first);
// }

void	store_map(t_map *m, char **line)
{
	int		lines;

	lines = 0;

	m->m = (char **)malloc(sizeof(char *) * m->my + 1);
	m->m[m->my] = NULL;
	while (lines < m->my)
	{
		get_next_line(0, line);
		m->m[lines++] = ft_strdup(*line + 4);
	}
	lines = 0;
	get_next_line(0, line);
}

void	store_token(t_token *t, char **line)
{
	int		lines;

	lines = 0;
	t->ty = ft_atoi(ft_strchr(*line, ' '));
	t->tx = ft_atoi(ft_strchr(ft_strchr(*line, ' ') + 1, ' '));
	t->t = (char **)malloc(sizeof(char *) * t->ty + 1);
	t->t[t->ty] = NULL;
	while (lines < t->ty)
	{
		get_next_line(0, line);
		t->t[lines++] = ft_strdup(*line);
	}
	lines = 0;
}

void	store(t_map *m, t_player *p, t_token *t, char **line)
{
	if (!ft_strncmp(*line, "$$$", 3))
	{
		p->p1 = *(*line + 10) == '1' ? 'O' : 'X';
		p->p2 = (p->p1 == 'O' ? 'X' : 'O');
		get_next_line(0, line);
	}
	if (!ft_strncmp(*line, "Plateau", 7))
	{
		m->my = ft_atoi(ft_strchr(*line, ' '));
		m->mx = ft_atoi(ft_strrchr(*line, ' '));
		get_next_line(0, line);
	}
	if (!ft_strncmp(*line, "    0", 5))
		store_map(m, line);
	if (!ft_strncmp(*line, "Piece", 5))
		store_token(t, line);
}

int		main(void)
{
	t_map		m;
	t_player	p;
	t_token		t;
	char		*line;
	while (1)
	{
		if (get_next_line(0, &line) > 0)
		{
			p.pos[0] = 0;
			p.pos[1] = 0;
			store(&m, &p, &t, &line);
			token_params(&t);
			token_placement(&m, &t, &p);
			ft_putnbr_fd(p.pos[0], 1);
			write(1, " ", 1);
			ft_putnbr_fd(p.pos[1], 1);
			ft_putchar('\n');
		}
		else
			break;
		if (m.m && t.t)
		{
			free(m.m);
			free(t.t);
		}
		free(line);
	}
}
