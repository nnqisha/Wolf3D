/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:45:29 by nnqisha           #+#    #+#             */
/*   Updated: 2018/06/16 14:45:31 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;

	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	while (*big && len <= n--)
	{
		if (ft_memcmp(big++, little, len) == 0)
			return ((char *)big - 1);
	}
	return (NULL);
}
