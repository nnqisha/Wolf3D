/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:43:28 by nnqisha           #+#    #+#             */
/*   Updated: 2018/06/16 14:43:29 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	else
	{
		while (--n && *s1 && *s2 && ((unsigned char)*s1 == (unsigned char)*s2))
		{
			++s1;
			++s2;
		}
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
