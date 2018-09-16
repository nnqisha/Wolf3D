/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:01:56 by nnqisha           #+#    #+#             */
/*   Updated: 2018/09/16 16:19:54 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_line(const char *s, char c)
{
	char	**split;
	int		ret;

	split = ft_strsplit(s, ' ');
	ret = 0;
	while (split[ret])
	{
		free(split[ret]);
		ret++;
	}
	free(split);
	return (ret);
}
