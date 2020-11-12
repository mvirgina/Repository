/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:02:43 by mvirgina          #+#    #+#             */
/*   Updated: 2020/11/09 19:32:12 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_return_0(void)
{
	char			*result;

	if (!(result = (char *)malloc(sizeof(char) * 1 + 1)))
		return (0);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static long int		ft_count_str(long int str)
{
	long int		buf;
	long int		length;

	buf = str;
	length = 0;
	while (buf != 0)
	{
		buf = buf / 10;
		length++;
	}
	return (length);
}

char				*ft_itoa(int n)
{
	int				is_neg;
	long int		length;
	long int		nb;
	int				i;
	char			*result;

	if (n == 0)
		return (ft_return_0());
	is_neg = n < 0 ? 1 : 0;
	nb = n;
	nb = is_neg ? nb * -1 : nb;
	length = ft_count_str(nb);
	if (!(result = (char *)malloc(sizeof(char) * (length + is_neg) + 1)))
		return (0);
	if (is_neg)
		result[0] = '-';
	i = 0;
	while (nb != 0)
	{
		result[length - 1 + is_neg - i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	result[length + is_neg] = '\0';
	return (result);
}
