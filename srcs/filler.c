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

void	find_params(t_token *t, int i, int j, int first)
{
	while (i < t->ty)
	{
		j = 0;
		while (j < t->tx)
		{
			// if (ft_strchr(t->t[i], '*') && !first)
			// {
			// 	t->up = i;
			// 	t->left = i;
			// 	first = 1;
			// }
			// if (t->t[i][j] == '*' && t->down < i)
			// 	t->down = i;
			// if (t->t[i][j] == '*' && t->left > j)
			// 	t->left = j;
			// if (t->t[i][j] == '*' && t->right < j)
			// 	t->right = j;
			// fprintf(stderr, "%ce", t->t[i][j]);
			// fflush(stdout);
			j++;
			first++;
		}
		fprintf(stderr, "\n");
		fflush(stdout);
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
	t->up = 0;
	t->down = 0;
	t->left = 0;
	t->right = 0;
	find_params(t, i, j, first);
	fprintf(stderr, MAG "t->up: %d\nt->left: %d\nt->right: %d\nt->down: %d\n", t->up, t->left, t->right, t->down);
}

void	store_map(t_map *m, char **line)
{
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
}

void	store_token(t_token *t, char **line)
{
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
	// fprintf(stderr, YEL "%d%c\n" RESET, num++, t->t[0][0]);
	// fflush(stdout);
}

void	store(t_map *m, t_player *p, t_token *t, char **line)
{
	fprintf(stderr, RED "First line: %s\n" RESET, *line);
	fflush(stdout);
	if (!ft_strncmp(*line, "$$$", 3))
	{
		fprintf(stderr, "%s\n", *line + 10);
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
	fprintf(stderr, "%chere\n", t->t[0][0]);
	fflush(stdout);
	fprintf(stderr, RED "End of storing\n" RESET);
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
		get_next_line(0, &line);
		store(&m, &p, &t, &line);
		token_params(&t);
		// fprintf(stderr, "%se", m.m[0]);
		// fflush(stdout);
		fprintf(stderr, RED "Last line: %s\n" RESET, line);
		fflush(stdout);
		write(1, "8 2\n", 4);
		if (m.m && t.t)
		{
			free(m.m);
			free(t.t);
		}
		free(line);
	}
}
