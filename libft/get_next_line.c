/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdu-toi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:59:26 by rdu-toi           #+#    #+#             */
/*   Updated: 2018/07/10 01:05:59 by rdu-toi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	line_check(int fd, t_get *gnl)
{
	char	*string;

	while (!ft_is_char(gnl->temp, gnl->n_line))
	{
		gnl->ret = read(fd, gnl->buffer, BUFF_SIZE);
		string = ft_strdup(gnl->temp);
		ft_strdel(&gnl->temp);
		gnl->temp = ft_strjoin(string, gnl->buffer);
		ft_strdel(&string);
		ft_strclr(gnl->buffer);
		if (gnl->ret == 0)
			break ;
	}
	ft_strdel(&gnl->buffer);
}

int		status(t_get *gnl, char **line, char *str)
{
	if (gnl->ret > 0 || ft_strlen(*line) || ft_strlen(str))
		return (1);
	if (gnl->ret < 0)
		return (-1);
	else
		return (0);
}

void	line_return(t_get *gnl, char **str, char **line)
{
	if (ft_is_char(gnl->temp, gnl->n_line))
	{
		ft_strdel(&*str);
		*str = ft_strdup_index(gnl->temp, gnl->n_line);
		gnl->i = ft_char_index(gnl->temp, gnl->n_line) + 1;
		*line = ft_strdup(*str);
		gnl->ret = 1;
		ft_strdel(&*str);
		*str = ft_strdup(gnl->temp + gnl->i);
		ft_strdel(&gnl->temp);
	}
	else
	{
		*line = ft_strdup(gnl->temp);
		ft_strclr(*str);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	t_get		gnl;

	gnl.n_line = '\n';
	if (fd < 0 || !line || read(fd, NULL, 0) ||
			!(gnl.buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!str)
		str = ft_strdup("");
	gnl.temp = ft_strdup(str);
	line_check(fd, &gnl);
	line_return(&gnl, &str, line);
	return (status(&gnl, line, str));
}
