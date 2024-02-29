/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:17:23 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/21 15:58:15 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*data;
	int			incr;

	incr = 0;
	data = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!data)
		return (NULL);
	while (incr < ac)
	{
		data[incr].size = ft_strlen(av[incr]);
		data[incr].str = malloc(sizeof(char) * (data[incr].size + 1));
		data[incr].copy = malloc(sizeof(char) * (data[incr].size + 1));
		if (!data[incr].str || !data[incr].copy)
		{
			free(data);
			return (NULL);
		}
		ft_strcpy(data[incr].str, av[incr]);
		ft_strcpy(data[incr].copy, data[incr].str);
		incr++;
	}
	data[incr].str = "0";
	data[incr].size = 0;
	data[incr].copy = "0";
	return (data);
}
