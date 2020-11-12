/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvirgina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:27:52 by mvirgina          #+#    #+#             */
/*   Updated: 2020/11/12 11:06:32 by mvirgina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				**ft_error(char **tab)
{
	unsigned int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static void				ft_get_str(char **n_str, unsigned int *n_strl, char c)
{
	unsigned int		i;

	*n_str += *n_strl;
	*n_strl = 0;
	i = 0;
	while (**n_str && **n_str == c)
		(*n_str)++;
	while ((*n_str)[i])
	{
		if ((*n_str)[i] == c)
			return ;
		(*n_strl)++;
		i++;
	}
}

static unsigned int		ft_get_numbers_strs(char const *s, char c)
{
	unsigned int		i;
	unsigned int		strs;

	if (!s[0])
		return (0);
	i = 0;
	strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		strs++;
	return (strs);
}

char					**ft_split(char const *s, char c)
{
	char				**tab;
	char				*next_str;
	unsigned int		next_str_len;
	unsigned int		strs;
	unsigned int		i;

	if (!s)
		return (NULL);
	strs = ft_get_numbers_strs(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (strs + 1))))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < strs)
	{
		ft_get_str(&next_str, &next_str_len, c);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1))))
			return (ft_error(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
