/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:46:17 by nnqisha           #+#    #+#             */
/*   Updated: 2018/06/16 14:46:18 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pos;

	i = 0;
	pos = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			pos = ((char*)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char*)&s[i]);
	return (pos);
}
