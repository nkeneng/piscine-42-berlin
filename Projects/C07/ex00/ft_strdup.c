/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:08:41 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/20 12:16:51 by snkeneng         ###   ########.fr       */
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

void	ft_strcpy(char *dest, char *src)
{
	int	incr;

	incr = 0;
	while (src[incr])
	{
		dest[incr] = src[incr];
		incr++;
	}
	dest[incr] = src[incr];
}

char	*ft_strdup(char *src)
{
	char	*str;

	str = malloc(ft_strlen(src) + 1 * sizeof(char));
	ft_strcpy(str, src);
	return (str);
}
