/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:56:02 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/13 10:14:17 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}

static char	*fill(const char *s, size_t start, size_t end)
{
	size_t		i;
	char		*tab;

	i = 0;
	tab = malloc(sizeof(char) * (end - start + 1));
	if (!tab)
		return (NULL);
	while (start < end)
	{
		tab[i++] = s[start];
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

static void	ft_free(char	**str, int idx)
{
	while (idx > 0)
	{
		free(str[idx - 1]);
		idx--;
	}
	free(str);
}

char	**ft_ss(char **tab, char c, const char *s)
{
	size_t	i;
	size_t	idx;
	size_t	j;

	idx = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
		{
			tab[idx++] = fill(s, j, i);
			if (!tab[idx - 1])
				return (ft_free(tab, idx), NULL);
		}
	}
	tab[idx] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_ss(tab, c, s));
}