/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:42:27 by nnqisha           #+#    #+#             */
/*   Updated: 2018/06/16 14:42:29 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
