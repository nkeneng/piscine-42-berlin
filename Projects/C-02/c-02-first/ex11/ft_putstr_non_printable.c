/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:20:21 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 18:36:56 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_to_hex(int i);
void	ft_swap(char *c, int size);
int		ft_is_not_printable(int i);

void	ft_putstr_non_printable(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr] != '\0')
	{
		if (ft_is_not_printable(str[incr]) == 1)
		{
			ft_convert_to_hex(str[incr]);
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

void	ft_convert_to_hex(int i)
{
	char	*hex_chars;
	char	c[2];
	int		incr;

	incr = 0;
	hex_chars = "0123456789abcdef";
	while (i > 0)
	{
		c[incr] = hex_chars[i % 16];
		i = i / 16;
		incr++;
	}
	if (incr <= 1)
		c[incr++] = '0';
	c[incr] = '\0';
	ft_swap(c, 2);
	write(1, "\\", 1);
	write(1, c, 2);
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
