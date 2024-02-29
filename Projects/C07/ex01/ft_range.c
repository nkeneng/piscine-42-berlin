/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:17:33 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/20 13:31:49 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	incr;

	if (min >= max)
		return (NULL);
	result = malloc(sizeof(int) * (max - min));
	incr = min;
	while (incr < max)
	{
		result[incr - min] = incr;
		incr++;
	}
	return (result);
}
