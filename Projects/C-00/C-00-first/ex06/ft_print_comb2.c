/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:15:40 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/03 12:07:30 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display(char x)
{
	write(1, &x, 1);
}

void	print_my_stuff(int a, int b)
{
	int	a_left;
	int	a_right;
	int	b_left;
	int	b_right;

	a_left = a / 10;
	a_right = a % 10;
	b_left = b / 10;
	b_right = b % 10;
	display(a_left + '0');
	display(a_right + '0');
	display(' ');
	display(b_left + '0');
	display(b_right + '0');
	if (a >= 98 && b >= 99)
	{
		return ;
	}
	display(',');
	display(' ');
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_my_stuff(a, b);
			b++;
		}
		a++;
	}
}
