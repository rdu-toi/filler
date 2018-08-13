/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:04:07 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/08/07 12:04:07 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

typedef struct 	s_map
{
	char		**m;
	int			mx;
	int			my;
}				t_map;

typedef struct 	s_token
{
	char		**t;
	int			tx;
	int			ty;
	int			top[2];
	int			bottom[2];
}				t_token;

typedef struct 	s_player
{
	char		p1;
	char		p2;
	int			pos[2];
}				t_player;

#endif
