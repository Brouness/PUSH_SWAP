/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:29:46 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/28 15:26:45 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strchr(char *str, int c)
{
	if (!str && c != '\0')
		return (0);
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*new;

	if (str == NULL)
		return (NULL);
	new = malloc(ft_strlen(str) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tab1;
	unsigned char		*tab2;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	tab1 = (unsigned char *)dest;
	tab2 = (unsigned char *)src;
	while (i < n)
	{
		tab1[i] = tab2[i];
		i++;
	}
	return (dest);
}

static char	*ft_function(size_t l, const char *str, int start, char *tab)
{
	size_t		i;

	i = 0;
	while (i < l && str[start + i])
	{
		tab[i] = str[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*tab;
	char	*khawi;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		khawi = malloc(1);
		if (khawi == NULL)
			return (NULL);
		khawi[0] = '\0';
		return (khawi);
	}
	if (len > slen - start)
		len = slen - start;
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	return (ft_function(len, s, start, tab));
}
