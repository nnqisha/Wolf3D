/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:24:21 by nnqisha           #+#    #+#             */
/*   Updated: 2018/06/16 14:24:24 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	long	tmp;
	int		len;

	tmp = n;
	len = (n <= 0 ? 2 : 1);
	while (n && ++len)
		n /= 10;
	if (!(s = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	s[--len] = '\0';
	if (tmp <= 0)
		s[0] = (tmp < 0 ? '-' : '0');
	while (tmp)
	{
		s[--len] = (tmp < 0 ? -tmp : tmp) % 10 + '0';
		tmp /= 10;
	}
	return (s);
}
