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

int	isset(const char *set, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len && src[i] && set[i])
	{
		j = 0;
		while (i + j < len && src[i + j] == set[i + j])
			j++;
		if (set[j] == '\0')
				return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	const char	*s;
	char		*ret;

	i = 0;
	s = s1;
	while (*s)
	{
		if (isset(set, *s))
			i++;
		s++;
	}
	ret = malloc((s - s1 - i) + 1);
	if (ret == NULL)
		return (NULL);
	s = ret;
	while (*s1)
	{
		if (!isset(set, *s1))
			*ret++ = *s1;
		s1++;
	}
	*ret = '\0';
	return ((char *)s);
}
