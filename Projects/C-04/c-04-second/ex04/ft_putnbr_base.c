/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:22:52 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/14 14:52:45 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr])
		incr++;
	return (incr);
}

int	base_len_is_correct(int bl)
{
	if (bl > 1)
		return (1);
	return (0);
}

int	check_base_validity(char *str)
{
	int	incr;
	int	sub_incr;

	incr = 0;
	sub_incr = 0;
	while (str[incr])
	{
		sub_incr = incr + 1;
		while (str[sub_incr])
		{
			if (str[incr] == str[sub_incr])
				return (0);
			if (str[sub_incr] == '+' || str[sub_incr] == '-')
				return (0);
			sub_incr++;
		}
		incr++;
	}
	return (1);
}

void	print_base(int nb, char *base, int base_len)
{
	long	nb_long;

	nb_long = (long)nb;
	if (nb_long < 0)
	{
		write(1, "-", 1);
		nb_long *= -1;
	}
	if (nb_long >= base_len)
	{
		print_base(nb_long / base_len, base, base_len);
		nb_long = nb_long % base_len;
	}
	write(1, &base[nb_long], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	bl;
	int	bl_correct;
	int	b_valid;

	bl = ft_strlen(base);
	b_valid = check_base_validity(base);
	bl_correct = base_len_is_correct(bl);
	if (!bl_correct || !b_valid)
		return ;
	print_base(nbr, base, bl);
}
