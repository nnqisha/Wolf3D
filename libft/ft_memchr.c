/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:29:35 by nnqisha           #+#    #+#             */
/*   Updated: 2017/09/11 16:30:21 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	i = 0;
	s1 = (unsigned char*)s;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
