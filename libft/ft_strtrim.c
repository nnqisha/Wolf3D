/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:47:50 by nnqisha           #+#    #+#             */
/*   Updated: 2018/06/16 14:47:53 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	len = 0;
	if (s != NULL)
	{
		while (start < ft_strlen(s) && ft_isspace(s[start]))
			start++;
		end = ft_strlen(s) - 1;
		while (end > start && ft_isspace(s[end]))
			end--;
		len = end - start + 1;
	}
	return (ft_strsub(s, start, len));
}
