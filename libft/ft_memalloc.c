/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:19:50 by oespion           #+#    #+#             */
/*   Updated: 2018/04/04 14:40:47 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	zone = NULL;
	if (size >= 2147483648)
		return (zone);
	zone = malloc(sizeof(size));
	if (zone)
		ft_bzero(zone, size);
	return (zone);
}
