/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnqisha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:46:39 by nnqisha           #+#    #+#             */
/*   Updated: 2018/06/22 15:20:02 by nnqisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_words(char const *s, char c)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
			{
				i++;
				size++;
			}
		}
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	size;
	int		i;
	int		start;

	i = 0;
	size = 0;
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tab[size++] = ft_strsub(s, start, i - start);
		}
	}
	tab[size] = NULL;
	return (tab);
}
