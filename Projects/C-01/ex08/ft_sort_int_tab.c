/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:12:31 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/03 20:24:52 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	incr;
	int	loop;
	int	temp;

	loop = 0;
	while (loop < size - 1)
	{
		incr = 0;
		while (incr < size - loop - 1)
		{
			if (incr + 1 < size)
			{
				if (tab[incr] > tab[incr + 1])
				{
					temp = tab[incr];
					tab[incr] = tab[incr + 1];
					tab[incr + 1] = temp;
				}
			}
			incr++;
		}
		loop++;
	}
}
