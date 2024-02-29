/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:56:43 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/03 16:55:34 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_my_stuff(int x, int y, int z)
{
	char	x_c;
	char	y_c;
	char	z_c;
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	x_c = x + '0';
	y_c = y + '0';
	z_c = z + '0';
	write(1, &x_c, 1); 
	write(1, &y_c, 1); 
	write(1, &z_c, 1);
	if (x >= 7 && y >= 8 && z >= 9)
	{
		return ;
	}
	write(1, &comma, 1); 
	write(1, &space, 1); 
}

void	ft_print_comb(void)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	while (x <= 7)
	{
		y = x + 1;
		while (y <= 8)
		{
			z = y + 1;
			while (z <= 9)
			{
				print_my_stuff(x, y, z);
				z++;
			}
			y++;
		}
		x++;
	}
}
