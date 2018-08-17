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
