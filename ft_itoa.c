/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:56:42 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/06 13:41:55 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n / 10.0 > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	fill_num(char *res, long long n, int len)
{
	if (n == 0)
	{
		res[0] = '0';
		return ;
	}
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n / 10.0 > 0)
	{
		res[--len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = calc_len(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	fill_num(res, n, len);
	return (res);
}
