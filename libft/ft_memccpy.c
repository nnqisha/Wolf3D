/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:25:49 by nnqisha           #+#    #+#             */
/*   Updated: 2018/06/16 14:25:51 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*s1;
	char			*s2;
	char			*s3;

	s1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	s3 = 0;
	while (i < n && s3 == 0)
	{
		s1[i] = s2[i];
		if (s2[i] == ((char)c))
			s3 = s1 + i + 1;
		i++;
	}
	return (s3);
}
