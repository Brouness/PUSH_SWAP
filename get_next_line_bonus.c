/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourajl <ybourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:22:44 by ybourajl          #+#    #+#             */
/*   Updated: 2026/02/28 15:26:36 by ybourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_search(char *tmp, char *buff)
{
	char	*keep_tmp;
	int		len;

	len = 0;
	keep_tmp = NULL;
	if (tmp)
	{
		keep_tmp = ft_strdup(tmp);
		free(tmp);
		len = ft_strlen(buff) + ft_strlen(keep_tmp);
		tmp = (char *)malloc(len + 1);
		if (tmp == NULL)
			return (NULL);
		ft_memcpy(tmp, keep_tmp, ft_strlen(keep_tmp) + 1);
		tmp[ft_strlen(keep_tmp)] = '\0';
		ft_memcpy(ft_strchr(tmp, '\0'), buff, ft_strlen(buff));
		tmp[len] = '\0';
		free(keep_tmp);
	}
	else if (!tmp)
		tmp = ft_strdup(buff);
	return (tmp);
}

void	ft_extract(char **ptr_tmp)
{
	char	*keep_tmp;

	keep_tmp = ft_strdup(ft_strchr(*ptr_tmp, '\n') + 1);
	free(*ptr_tmp);
	*ptr_tmp = keep_tmp;
}

char	*ft_finish(char **ptr_tmp, char **ptr_buff, ssize_t b)
{
	char	*line;

	line = NULL;
	if (*ptr_tmp && **ptr_tmp && b == 0)
	{
		line = ft_strdup(*ptr_tmp);
		free(*ptr_tmp);
		*ptr_tmp = NULL;
		free(*ptr_buff);
		*ptr_buff = NULL;
		return (line);
	}
	if (ft_strchr(*ptr_tmp, '\n') != NULL)
	{
		line = ft_substr(*ptr_tmp, 0, (ft_strlen(*ptr_tmp)
					- ft_strlen(ft_strchr(*ptr_tmp, '\n'))) + 1);
		ft_extract(ptr_tmp);
		return (line);
	}
	free(*ptr_tmp);
	*ptr_tmp = NULL;
	free(*ptr_buff);
	*ptr_buff = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*tmp ;
	char			*buff;
	ssize_t			read_return;

	buff = NULL;
	read_return = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read_return != 0)
	{
		if (tmp && ft_strchr(tmp, '\n') != NULL)
			return (ft_finish(&tmp, &buff, read_return));
		buff = (char *)malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return (NULL);
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return <= 0)
			break ;
		buff[read_return] = '\0';
		tmp = ft_search(tmp, buff);
		free(buff);
		buff = NULL;
	}
	return (ft_finish(&tmp, &buff, read_return));
}
