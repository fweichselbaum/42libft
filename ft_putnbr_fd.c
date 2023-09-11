/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:56:16 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/06 15:15:24 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	char		digits[10];
	long long	lnb;

	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	lnb = (long long) n;
	if (lnb < 0)
	{
		write(fd, "-", 1);
		lnb = -lnb;
	}
	while (lnb > 0)
	{
		digits[i++] = (lnb % 10) + '0';
		lnb /= 10;
	}
	while (--i >= 0)
		write(fd, digits + i, 1);
}
