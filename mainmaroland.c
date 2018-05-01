/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainmaroland.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:02:09 by oespion           #+#    #+#             */
/*   Updated: 2018/05/01 14:08:02 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int            main(int argc, char **argv)
{
    char    *line;
    int        fd;
    int        ret;

    (void)argc;
    fd = open(argv[1], 0);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
		printf("%s%d\n", line, ret);
    	ft_strdel(&line);
    }
	ft_strdel(&line);
	while (1)
		;
    return (0);
}
