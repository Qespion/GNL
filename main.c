/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 10:04:29 by oespion           #+#    #+#             */
/*   Updated: 2018/04/30 10:29:57 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		i;

	i = open(av[1], 0);
	printf("%d\n", get_next_line(i, &line));
	printf("%s\n", line);
	ft_strdel(&line);
	printf("%d\n", get_next_line(i, &line));
	printf("%s\n", line);
	ft_strdel(&line);
	printf("%d\n", get_next_line(i, &line));
	printf("%s\n", line);
	ft_strdel(&line);
	printf("%d\n", get_next_line(i, &line));
	printf("%s\n", line);
	ft_strdel(&line);
	printf("%d\n", get_next_line(i, &line));
	printf("%s\n", line);
	ft_strdel(&line);
	printf("%d\n", get_next_line(i, &line));
	printf("%s\n", line);
	ft_strdel(&line);
	printf("%d\n", get_next_line(i, &line));
	printf("%s\n", line);
	ft_strdel(&line);
	printf("%d\n", get_next_line(i, &line));
	printf("%s\n", line);
	ft_strdel(&line);
	printf("%d\n", get_next_line(i, &line));
	printf("%s\n", line);
	ft_strdel(&line);
	return (0);
}
