/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_nbr_size(long num)
{
	size_t	i;

	i = 0;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c[11];
	long	num;
	size_t	i;
	size_t	size;

	num = n;
	if (num == 0)
	{
		ft_putstr_fd("0", fd);
		return ;
	}
	size = ft_get_nbr_size(num);
	i = size;
	if (num < 0)
	{
		c[0] = '-';
		num *= -1;
	}
	c[i] = '\0';
	while (num)
	{
		c[--i] = (num % 10) + '0';
		num /= 10;
	}
	write(fd, c, size);
}
