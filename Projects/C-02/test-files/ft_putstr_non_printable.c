/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:20:21 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/06 17:15:27 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_not_printable(int i);
void	ft_convert_to_hex(int i, char *c);
void	ft_swap(char *c, int size);

void	hex_array(char *c)
{
	c[0] = '0';
	c[1] = '1';
	c[2] = '2';
	c[3] = '3';
	c[4] = '4';
	c[5] = '5';
	c[6] = '6';
	c[7] = '7';
	c[8] = '8';
	c[9] = '9';
	c[10] = 'a';
	c[11] = 'b';
	c[12] = 'c';
	c[13] = 'd';
	c[14] = 'e';
	c[15] = 'f';
}

void	ft_putstr_non_printable(char *str)
{
	int	incr;
	int	val;
	char	hex[2];
	char	slash;

	incr = 0;
	slash = '\\';
	val = str[incr];
	while (val > 0)
	{
		val = str[incr];
		if (ft_is_not_printable(val) == 1)
		{
			ft_convert_to_hex(val, hex);
			if ((int)hex[0] > 0)
			{
				write(1, &slash, 1);
				write(1, hex, 2);
			}
		}
		else
			write(1, &str[incr], 1);
		incr++;
	}
}

int	ft_is_not_printable(int i)
{
	if (i <= 31 || i >= 127)
	{
		return (1);
	}
	return (0);
}

void	ft_convert_to_hex(int i, char *c)
{
	char	hex_chars[16];
	int	rest;
	int	incr;

	incr = 0;
	hex_array(hex_chars);
	while (i > 0)
	{
		rest = i % 16;
		c[incr] = hex_chars[rest];
		i = i / 16;
		incr++;
	}
	if (incr <= 1)
		c[incr++] = '0';
	c[incr] = '\0';
	ft_swap(c, 2);
}

void	ft_swap(char *c, int size)
{
	int	temp;
	int	incr;

	incr = 0;
	while (incr < size / 2)
	{
		temp = c[incr];
		c[incr] = c[size - incr - 1];
		c[size - incr - 1] = temp;
		incr++;
	}
}
