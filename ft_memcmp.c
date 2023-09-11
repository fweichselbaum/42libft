/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:45:56 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/05 09:50:05 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	v1;
	unsigned char	v2;

	i = 0;
	while (i < n)
	{
		v1 = *((unsigned char *)(s1 + i));
		v2 = *((unsigned char *)(s2 + i));
		if (v1 != v2)
			return (v1 - v2);
		i++;
	}
	return (0);
}
