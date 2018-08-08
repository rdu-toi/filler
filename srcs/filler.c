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

void	gnl(t_map *m, t_player *p)
{
	char		*line;
	int			lines;

	lines = 0;
	get_next_line(0, &line);
	fprintf(stderr, GRN "%s" RESET, line);
	write(2, "\n", 1);
	if (!ft_strncmp(line, "$$$", 3))
	{
		p->p1 = (line[10] == '1' ? 'O' : 'X');
		p->p2 = (p->p1 == 'O' ? 'X' : 'O');
		ft_putchar_fd(p->p1, 2);
		write(2, "\n", 1);
		ft_putchar_fd(p->p2, 2);
		write(2, "\n", 1);
		gnl(m, p);
	}
	else if (!ft_strncmp(line, "Plateau", 7))
	{
		m->my = ft_atoi(ft_strchr(line, ' '));
		m->mx = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
		fprintf(stderr, RED "m->my = %d\n" RESET, m->my);
		fprintf(stderr, RED "m->mx = %d\n" RESET, m->mx);
		gnl(m, p);
	}
	else if (!ft_strncmp(line, "    0", 5))
	{
		m->m = (char **)malloc(sizeof(char *) * m->my);
		m->m[m->my] = NULL;
		fprintf(stderr, BLU "m->my = %d\n" RESET, m->my);
		fprintf(stderr, BLU "m->mx = %d\n" RESET, m->mx);
		while (lines < m->my)
		{
			ft_putstr_fd(MAG "", 2);
			ft_putnbr_fd(lines, 2);
			//m.m[lines] = ft_strnew((size_t)m.mx);
			get_next_line(0, &line);
			//ft_strcpy(m.m[lines], (line + 4));
			m->m[lines] = ft_strdup(line + 4);
			lines++;
		}
		lines = 0;
		while (m->m[lines])
		{
			ft_putstr_fd(YEL "", 2);
			ft_putnbr_fd(lines, 2);
			ft_putstr_fd(m->m[lines++], 2);
			write(2, "\n", 1);
			ft_putstr_fd(RESET "", 2);
		}
	}
}

int		main(void)
{

	t_map		m;
	t_player	p;
	//t_token		t;
	gnl(m, p);
	return (0);
}
