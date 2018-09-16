/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:08:53 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/16 16:36:23 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void		get_lines(char *str, t_wolf *a)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	line = NULL;
	a->y = 0;
	if (get_next_line(fd, &line))
	{
		a->x = ft_count_line(line, ' ');
		free(line);
	}
	while (get_next_line(fd, &line))
	{
		a->y++;
		free(line);
	}
	a->row = a->x;
	close(fd);
}

void		ft_free2dchar(char **st)
{
	int		i;

	i = 0;
	while (st[i])
	{
		free(st[i]);
		i++;
	}
	free(st);
	st = NULL;
}

void		read_map(char *str, t_wolf *a)
{
	a->fill_mapx = 0;
	a->fill_mapy = 0;
	a->fd = open(str, O_RDONLY);
	while (get_next_line(a->fd, &a->line) > 0 && a->fill_mapy < a->y)
	{
		if ((ft_count_line(a->line, ' ')) >= a->row)
		{
			a->stream = ft_strsplit(a->line, ' ');
			a->fill_mapx = 0;
			while (a->fill_mapx < a->x)
			{
				a->worldmap[a->fill_mapy][a->fill_mapx] =
					(int)ft_atoi(a->stream[a->fill_mapx]);
				a->fill_mapx++;
			}
			a->fill_mapy++;
			free(a->line);
			ft_free2dchar(a->stream);
		}
		else
			ft_putendl("Map Error\n");
	}
	free(a->line);
	close(a->fd);
}

void		alloc_memo(char *str, t_wolf *a)
{
	int		i;

	i = 0;
	a->worldmap = (double**)malloc(sizeof(double*) * a->y);
	while (i < a->y)
	{
		a->worldmap[i] = (double*)malloc(sizeof(double) * a->x);
		i++;
	}
	read_map(str, a);
}
