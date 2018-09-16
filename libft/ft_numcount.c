/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:21:36 by nnqisha           #+#    #+#             */
/*   Updated: 2018/08/22 16:23:34 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numcount(const char *s)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]) && !ft_isdigit(s[i + 1]))
			count++;
	return (count);
}
