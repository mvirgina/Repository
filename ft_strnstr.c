/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:11:13 by mvirgina          #+#    #+#             */
/*   Updated: 2020/11/11 13:30:42 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle[0])
		return ((char*)haystack);
	if (ft_strlen(haystack) < needle_len || len < needle_len)
		return (NULL);
	i = 0;
	while (haystack[i] && i <= len - needle_len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
