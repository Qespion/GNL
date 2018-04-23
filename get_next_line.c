/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:21:39 by oespion           #+#    #+#             */
/*   Updated: 2018/04/23 13:17:40 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

s_struct	*ft_new(s_struct *strleft, const int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	if (!(strleft = (s_struct*)malloc(sizeof(s_struct))))
		return (0);
	strleft->allstring = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!strleft->allstring)
			strleft->allstring = ft_strdup(buff);
		else
		{
			tmp = strleft->allstring;
			strleft->allstring = ft_strjoin(strleft->allstring, buff);
			free(tmp);
		}
	}
	strleft->start = 0;
	strleft->full = 0;
	return (strleft);
}

int	ft_print_line(s_struct *strleft, char **line)
{
	int	r;
	int	len;

	r = 0;
	len = strleft->start;
	while (strleft->allstring[len] != '\n' && strleft->allstring[len] != '\0')
		len++;
	len -= strleft->start;
	*line = ft_strsub(strleft->allstring, strleft->start, len);
	strleft->start = strleft->start + len + 1;
	if (strleft->allstring[strleft->start - 1] == '\0')
	{
		free(strleft->allstring);
		free(strleft);
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static s_struct	*strleft;

	if (fd < 0 && fd > OPEN_MAX)
		return (-1);
	if (!(strleft))
		strleft = ft_new(strleft, fd);
	if (ft_print_line(strleft, line) == 1)
		return (1);
	return (0);
}