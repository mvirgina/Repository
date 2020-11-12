/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:43:44 by mvirgina          #+#    #+#             */
/*   Updated: 2020/11/09 17:20:44 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!(dst = malloc(size * count)))
		return (NULL);
	while ((size * count) > i)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
