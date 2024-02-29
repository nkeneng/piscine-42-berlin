/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:41:06 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/03 19:09:33 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	incr;

	incr = 0;
	while (incr < size / 2)
	{
		temp = tab[incr];
		tab[incr] = tab[size - incr - 1];
		tab[size - incr - 1] = temp;
		incr++;
	}
}
