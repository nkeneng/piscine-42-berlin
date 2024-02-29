/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbotel <cbotel@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:36:04 by cbotel            #+#    #+#             */
/*   Updated: 2024/02/03 16:41:06 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_line(int index, char fi_ca, char mid_ca, char end_ca)
{
	int	incr;

	if (index > 0)
	{
		ft_putchar(fi_ca);
		if (index > 1)
		{
			incr = 1;
			while (incr < (index - 1))
			{
				ft_putchar(mid_ca);
				incr++;
			}
			ft_putchar(end_ca);
		}
	}
}

void	rush(int x, int y)
{
	int	incr;

	if (y > 0 && x > 0)
	{
		ft_print_line(x, 'A', 'B', 'C');
		ft_putchar('\n');
		if (y > 1)
		{
			incr = 1;
			while (incr < (y - 1))
			{
				ft_print_line(x, 'B', ' ', 'B');
				ft_putchar('\n');
				incr++;
			}
			ft_print_line(x, 'A', 'B', 'C');
		}
	}
	else
	{
		write(1, "Marvin only likes positive Numbers please!", 42);
	}
}
