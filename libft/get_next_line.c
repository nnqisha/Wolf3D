/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:46:04 by nnqisha           #+#    #+#             */
/*   Updated: 2018/08/26 10:06:57 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			verify_line(char **batch, char **line)
{
	char			*tmp_batch;
	char			*strchr_batch;
	int				i;

	i = 0;
	strchr_batch = *batch;
	while (strchr_batch[i] != '\n')
		if (!strchr_batch[i++])
			return (0);
	tmp_batch = &strchr_batch[i];
	*tmp_batch = '\0';
	*line = ft_strdup(*batch);
	free(*batch);
	*batch = ft_strdup(tmp_batch + 1);
	return (1);
}

static	int			read_file(int fd, char *heap, char **batch, char **line)
{
	int				ret;
	char			*tmp_batch;

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*batch)
		{
			tmp_batch = *batch;
			*batch = ft_strjoin(tmp_batch, heap);
			free(tmp_batch);
			tmp_batch = NULL;
		}
		else
			*batch = ft_strdup(heap);
		if (verify_line(batch, line))
			break ;
	}
	return (RET_VALUE(ret));
}

void				copy_batch(char **batch, char **line)
{
	*line = *batch;
	*batch = NULL;
}

int					get_next_line(int const fd, char **line)
{
	static char		*batch[MAX_FD];
	char			*heap;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, batch[fd], 0) < 0) \
			|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if ((batch[fd]) && (verify_line(&batch[fd], line)))
		free(heap);
	else
	{
		i = 0;
		while (i < BUFF_SIZE)
			heap[i++] = '\0';
		ret = read_file(fd, heap, &batch[fd], line);
		free(heap);
		if (ret != 0 || batch[fd] == NULL || batch[fd][0] == '\0')
		{
			*line = (!ret && *line) ? NULL : *line;
			return (ret);
		}
		copy_batch(&batch[fd], line);
	}
	return (1);
}
