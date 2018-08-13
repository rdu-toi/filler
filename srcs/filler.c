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
	ft_putchar_fd('\n', 2);
}

int		*placement(t_map *m, t_token *t, t_player *p, int *pos, int mi, int mj, int ti, int tj, int i, int j)
{
	while (mi < m->mx)
	{
		mj = 0;
		while (mj < m->my)
		{
			ti = t->top[1];
			i = 0;
			while (ti <= t->bottom[1])
			{
				j = 0;
				tj = t->top[0];
				while (tj <= bottom[0])
				{
					if (mj + j == m->my || mi + i == m->mx)
					{
						w = 0;
						break;
					}
					if (m->m[mi + i][mj + j] == p->p2)
					{
						w = 0;
						break;
					}
					if (t->t[ti][tj] == '*' && m->m[mi + i][mj + j] == p->p1)
						w++;
					j++;
					tj++;
				}
				if (w == 1)
					return (pos);
				i++;
				ti++;
			}
			mj++;
		}
		mi++;
	}
}

int		*token_placement(t_map *m, t_token *t, t_player *p)
{
	int		mi;
	int		mj;
	int		ti;
	int		tj;
	int		i;
	int		j;

	mi = 0;
	mj = 0;
	i = 0;
	j = 0;
	ti = t->top[1];
	tj = t->top[0];
	return (placement(m, t, p, mi, mj, ti, tj, i, j))
}

void	find_params(t_token *t, int i, int j, int first)
{
	fprintf(stderr, MAG "Find_params function open!\n" RESET);
	fflush(stdout);
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
	fprintf(stderr, RED "Find_params function close!\n" RESET);
	fflush(stdout);
}

void	token_params(t_token *t)
{
	fprintf(stderr, MAG "Token_params function open!\n" RESET);
	fflush(stdout);
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
	fprintf(stderr, GRN "t->top: %d, %d\nt->bottom: %d, %d\n" RESET, t->top[0], t->top[1], t->bottom[0], t->bottom[1]);
	fprintf(stderr, RED "Token_params function close!\n" RESET);
	fflush(stdout);
}

void	store_map(t_map *m, char **line)
{
	fprintf(stderr, MAG "Store_map function open!\n" RESET);
	fflush(stdout);
	int		lines;
	int		num = 10;

	lines = 0;

	m->m = (char **)malloc(sizeof(char *) * m->my + 1);
	m->m[m->my] = NULL;
	while (lines < m->my)
	{
		get_next_line(0, line);
		m->m[lines++] = ft_strdup(*line + 4);
	}
	lines = 0;
	while (m->m[lines])
	{
		fprintf(stderr, YEL "%d%s\n" RESET, num++, m->m[lines++]);
		fflush(stdout);
	}
	get_next_line(0, line);
	fflush(stdout);
	fprintf(stderr, RED "Store_map function close!\n" RESET);
	fflush(stdout);
}

void	store_token(t_token *t, char **line)
{
	fprintf(stderr, MAG "Store_token function open!\n" RESET);
	fflush(stdout);
	int		lines;
	int		num = 10;

	lines = 0;
	t->ty = ft_atoi(ft_strchr(*line, ' '));
	t->tx = ft_atoi(ft_strchr(ft_strchr(*line, ' ') + 1, ' '));
	t->t = (char **)malloc(sizeof(char *) * t->ty + 1);
	t->t[t->ty] = NULL;
	fprintf(stderr, GRN "t->ty: %d\nt->tx: %d\n" RESET, t->ty, t->tx);
	fflush(stdout);
	while (lines < t->ty)
	{
		get_next_line(0, line);
		t->t[lines++] = ft_strdup(*line);
	}
	lines = 0;
	while (t->t[lines])
	{
		fprintf(stderr, YEL "%d%s\n" RESET, num++, t->t[lines++]);
		fflush(stdout);
	}
	fprintf(stderr, RED "Store_token function close!\n" RESET);
	fflush(stdout);
}

void	store(t_map *m, t_player *p, t_token *t, char **line)
{
	fprintf(stderr, MAG "Store function open!\n" RESET);
	fflush(stdout);
	if (!ft_strncmp(*line, "$$$", 3))
	{
		p->p1 = *(*line + 10) == '1' ? 'O' : 'X';
		p->p2 = (p->p1 == 'O' ? 'X' : 'O');
		fprintf(stderr, GRN "p->p1: %c\np->p2: %c\n" RESET, p->p1, p->p2);
		fflush(stdout);
		get_next_line(0, line);
	}
	if (!ft_strncmp(*line, "Plateau", 7))
	{
		m->my = ft_atoi(ft_strchr(*line, ' '));
		m->mx = ft_atoi(ft_strchr(*line, ' '));
		fprintf(stderr, GRN "m->my: %d\nm->mx: %d\n" RESET, m->my, m->mx);
		fflush(stdout);
		get_next_line(0, line);
	}
	if (!ft_strncmp(*line, "    0", 5))
		store_map(m, line);
	if (!ft_strncmp(*line, "Piece", 5))
		store_token(t, line);
	fprintf(stderr, RED "End of storing\n" RESET);
	fflush(stdout);
	fprintf(stderr, RED "Store function close!\n" RESET);
	fflush(stdout);
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
			fprintf(stderr, BLU "BEGINNING!\n" RESET);
			fflush(stdout);
			store(&m, &p, &t, &line);
			token_params(&t);
			fprintf(stderr, BLU "ENDING!\n" RESET);
			fflush(stdout);
		}
		write(1, "8 2\n", 4);
		if (m.m && t.t)
		{
			free(m.m);
			free(t.t);
		}
		free(line);
	}
}
