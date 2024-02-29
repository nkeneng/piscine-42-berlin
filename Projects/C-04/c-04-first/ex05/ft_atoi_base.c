/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:10:57 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/14 14:52:16 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 1 -> get index 0 -> get length*/
int	get_ind_len(char *str, char val, int type)
{
	int	incr;

	incr = 0;
	if (type == 1)
	{
		while (str[incr])
		{
			if (str[incr] == val)
				return (incr);
			incr++;
		}
		return (-1);
	}
	else
	{
		while (str[incr])
			incr++;
		return (incr);
	}
}

int	get_power(int val, int pow)
{
	int	result;

	result = 1;
	while (pow-- > 0)
		result = result * val;
	return (result);
}

int	ft_convert(int base_len, char *base, char *str)
{
	int	str_len;
	int	result;
	int	sign;
	int	incr;

	sign = 1;
	incr = 0;
	str_len = get_ind_len(str, 0, 0);
	if (str[0] == ' ' || str[0] == '+' || str[0] == '-')
	{
		while (str[incr] == ' ' || str[incr] == '+' || str[incr] == '-')
		{
			if (str[incr] == '-')
				sign *= -1;
			incr++;
		}
		str = str + incr;
		str_len = get_ind_len(str, 0, 0);
	}
	result = get_ind_len(base, str[0], 1) * get_power(base_len, str_len - 1);
	if (str_len <= 1)
		return (result);
	return (sign * (result + ft_convert(base_len, base, str + 1)));
}

int	ft_atoi_base(char *str, char *base)
{
	int	bl;
	int	incr;
	int	sub_incr;

	incr = 0;
	sub_incr = 0;
	while (base[incr])
	{
		sub_incr = incr + 1;
		while (base[sub_incr])
		{
			if (base[incr] == base[sub_incr] || base[incr] == ' ')
				return (0);
			if (base[sub_incr] == '+' || base[sub_incr] == '-')
				return (0);
			sub_incr++;
		}
		incr++;
	}
	bl = get_ind_len(base, 0, 0);
	if (bl <= 1)
		return (0);
	return (ft_convert(bl, base, str));
}
