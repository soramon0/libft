/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_word(char const *src, char c)
{
	char const	*s;

	s = src;
	while (*s)
	{
		if (*s == c)
			return (s - src);
		s++;
	}
	return (s - src);
}

size_t	ft_count_words(const char *s, char c, size_t len)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (s[i])
	{
		i += ft_count_word(&s[i], c);
		if (i > 0)
			ret++;
		if (i == len)
			return (ret);
		if (s[i] == c)
		{
			while (s[i + 1] && s[i + 1] == c)
			{
				i++;
				continue ;
			}
		}
		i++;
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
	size_t	offset;

	s = (char *)src;
	i = 0;
	offset = 0;
	while (*s && offset < len)
	{
		offset = ft_count_word(s, c);
		if (offset == 0 && *s == c && s++)
			continue ;
		ret[i] = ft_substr(src, s - src, offset);
		if (ret[i] == NULL)
			return (ft_cleanup(ret, i));
		s += offset;
		if (*s == c)
			s++;
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
