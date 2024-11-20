/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_count_word(char const *src, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (*src == c)
			return (i);
		i++;
		src++;
	}
	return (i);
}

size_t	ft_count_words(const char *s, char c, size_t len)
{
	size_t	ret;
	size_t	i;
	size_t	j;

	ret = 0;
	i = 0;
	j = 0;
	while (i < len)
	{
		j = ft_count_word(s, c, len - i);
		i += j;
		if (j > 0)
		{
			ret++;
			i++;
		}
		else
			i++;
		s += i;
	}
	return (ret);
}

char	**ft_cleanup(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**split_str(char **ret, char const *src, char c, size_t len)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	k;

	s = (char *)src;
	i = 0;
	j = 0;
	k = 0;
	while (*s && j < len)
	{
		k = ft_count_word(s, c, len - j);
		j += k;
		if (k == 0 && j++ && s++)
			continue ;
		ret[i] = ft_substr(src, s - src, k);
		if (ret[i] == NULL)
			return (ft_cleanup(ret, i));
		s += j + 1;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_split(char const *src, char c)
{
	char	**ret;
	size_t	len;

	len = ft_strlen(src);
	ret = (char **)malloc(sizeof(char *) * (ft_count_words(src, c, len) + 1));
	if (ret == NULL)
		return (NULL);
	return (split_str(ret, src, c, len));
}
