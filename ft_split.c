/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:33:42 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/06 17:54:29 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *str, char del)
{
	int	in_word;
	int	count;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (in_word && *str == del)
			in_word = 0;
		else if (!in_word && *str != del)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static void	cleanup(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	compute_part(const char *str, char del, char *dest, int pos)
{
	int	i;

	i = 0;
	if (dest)
		while (str[pos] && str[pos] != del)
			dest[i++] = str[pos++];
	while (str[pos] && str[pos] == del)
		pos++;
	return (pos);
}

static int	part_len(const char *str, char del, int pos)
{
	int	i;

	i = 0;
	while (str[pos + i] && str[pos + i] != del)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	int		i;
	int		pos;
	char	**arr;

	i = 0;
	len = count(s, c);
	arr = ft_calloc((len + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	pos = compute_part(s, c, NULL, 0);
	while (i < len)
	{
		arr[i] = ft_calloc(part_len(s, c, pos) + 1, sizeof(char));
		if (!arr[i])
		{
			cleanup(arr);
			return (NULL);
		}
		pos = compute_part(s, c, arr[i], pos);
		i++;
	}
	return (arr);
}
