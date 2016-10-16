/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:55:07 by eozdek            #+#    #+#             */
/*   Updated: 2016/03/29 05:36:29 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		line_cpy(char *str, char c)
{
	int i;

	i = 0;
	if (*str)
	{
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (i);
}

static char		*ft_strchr_mod(const char *s, char c)
{
	if (!(*s))
		return (NULL);
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
	{
		s++;
		return ((char *)s);
	}
	else
		return (NULL);
}

static int		ft_case(char **line, char **str)
{
	size_t	i;
	size_t	n;
	char	c;
	char	*tmp;

	i = ft_strlen(*str);
	tmp = *str;
	tmp = ft_strdup(*str);
	ft_strdel(str);
	c = ft_strchr(tmp, '\n') ? '\n' : '\0';
	n = line_cpy(tmp, c);
	if ((i = ft_strlen(tmp)) == 0)
	{
		*line = "";
		return (0);
	}
	*line = ft_strsub(tmp, 0, n);
	*str = c == '\n' ? ft_strdup(ft_strchr_mod(tmp, '\n')) : ft_strdup("");
	ft_strdel(&tmp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char *str[256];
	int			ret;
	int			i;
	char		*tmp;

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || fd > 256)
		return (-1);
	i = 0;
	str[fd] = str[fd] ? str[fd] : ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	return (i = ft_case(line, &(str[fd]))) ? i : 0;
}
