/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:32:01 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/20 15:26:15 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr])
		incr++;
	return (incr);
}

int	ft_total_len(char **strs, int size, char *sep)
{
	int	incr;
	int	len;
	int	tmp;

	incr = 0;
	len = 0;
	while (incr <= size - 1)
	{
		tmp = ft_strlen(strs[incr]);
		len += tmp;
		incr++;
	}
	len += (size -1) * ft_strlen(sep);
	return (len);
}

char	*ft_logic(int size, char **strs, char *sep, char *result)
{
	int		incr;
	int		sub_incr;
	int		sep_incr;

	incr = 0;
	sub_incr = 0;
	while (incr <= size - 1)
	{
		while (*strs[incr])
		{
			result[sub_incr++] = *strs[incr];
			strs[incr]++;
		}
		sep_incr = 0;
		if (incr++ < size - 1)
		{
			while (sep[sep_incr])
				result[sub_incr++] = sep[sep_incr++];
		}
	}
	result[sub_incr] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;

	if (size == 0)
	{
		result = malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	result = malloc(sizeof(char) * (ft_total_len(strs, size, sep) + 1));
	if (!result)
		return (NULL);
	return (ft_logic(size, strs, sep, result));
}
