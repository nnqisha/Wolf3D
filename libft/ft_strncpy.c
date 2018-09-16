/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:44:00 by nnqisha           #+#    #+#             */
/*   Updated: 2018/06/16 14:44:02 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if ((size_t)ft_strlen((char *)src) < len)
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		while (i < len)
		{
			dest[i] = '\0';
			i++;
		}
		return (dest);
	}
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
