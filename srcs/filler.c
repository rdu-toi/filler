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

void	gnl()
{
	t_map		m;
	//t_token		t;
	t_player	p;
	char		*line;
	int			lines;

	lines = 0;
	get_next_line(0, &line);
	ft_putstr_fd(line, 2);
	fprintf(stderr, GRN "%s" RESET, line);
	write(2, "\n", 1);
	if (line[0] == '$')
	{
		p.p1 = (line[10] == '1' ? 'O' : 'X');
		p.p2 = (p.p1 == 'O' ? 'X' : 'O');
		ft_putchar_fd(p.p1, 2);
		write(2, "\n", 1);
		ft_putchar_fd(p.p2, 2);
		write(2, "\n", 1);
		gnl();
	}
	//else if (!ft_strcmp(line, "Plateau"))
	else if (line[0] == 'P')
	{
		m.my = ft_atoi(ft_strchr(line, ' '));
		m.mx = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
		ft_putnbr_fd(m.my, 2);
		write(2, "\n", 1);
		ft_putnbr_fd(m.mx, 2);
		write(2, "\n", 1);
		gnl();
	}
	else if (line[0] == '0')
	{
		m.m = (char **)malloc(sizeof(char *) * m.my);
		m.m[m.my] = "\0";
		while (lines < m.my)
		{
			ft_putnbr_fd(lines, 2);
			m.m[lines] = ft_strnew((size_t)m.mx);
			get_next_line(0, &line);
			ft_strcpy(m.m[lines], (line + 4));
			lines++;
		}
		lines = 0;
		while (m.m[lines])
		{
			ft_putstr_fd(m.m[lines++], 2);
		}
	}
}

int		main(void)
{
	gnl();
	return (0);
}
