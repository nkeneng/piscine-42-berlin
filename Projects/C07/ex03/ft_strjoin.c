/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbotel <cbotel@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:51:21 by cbotel            #+#    #+#             */
/*   Updated: 2024/02/22 18:01:54 by cbotel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*comp_str(int size, char **strs, char *sep)
{
	char	*comp_str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += str_len(strs[i]);
		i++;
	}
	len += str_len(sep) * (size - 1);
	if (size <= 0)
		len = 1;
	comp_str = (char *) malloc((len + 1) * sizeof(char));
	if (!comp_str)
		return (NULL);
	return (comp_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		c;
	int		s;
	char	*str;

	str = comp_str(size, strs, sep);
	i = -1;
	s = 0;
	while (++i < size)
	{
		c = 0;
		while (strs[i][c])
		{
			str[s++] = strs[i][c];
			c++;
		}
		c = 0;
		while (sep[c] && i != size - 1)
		{
			str[s++] = sep[c];
			c++;
		}
	}
	str[s] = '\0';
	return (str);
}
