/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:58:41 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/08 16:12:02 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*return_my_work(char *str, int position)
{
	if (position >= 0)
	{
		if (position > 0)
			return (str + position - 1);
		else
			return (str);
	}
	return (NULL);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	incr;
	int	to_find_incr;
	int	position;

	incr = 0;
	to_find_incr = 0;
	position = 0;
	while (str[incr] != '\0' && to_find[to_find_incr] != '\0')
	{
		if (str[incr] == to_find[to_find_incr])
		{
			if (position <= 0)
				position = incr + 1;
			to_find_incr++;
		}
		else
		{
			position = -1;
			to_find_incr = 0;
		}
		incr++;
	}
	if (to_find[to_find_incr] != '\0' && position >= 0)
		position = -1;
	return (return_my_work(str, position));
}
