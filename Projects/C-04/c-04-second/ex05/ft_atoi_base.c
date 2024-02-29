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

int	str_valid(char *str, char *base)
{
	int	incr;
	int	found;
	int	b_incr;

	incr = 0;
	b_incr = 0;
	while (str[incr])
	{
		found = 0;
		if (str[incr] != '-' && str[incr] != '+')
		{
			b_incr = 0;
			while (base[b_incr])
			{
				if (str[incr] == base[b_incr])
					found = 1;
				b_incr++;
			}
			if (!found)
				return (incr);
		}
		incr++;
	}
	return (get_ind_len(str, 0, 0));
}

int	get_power(int val, int pow)
{
	int	result;

	result = 1;
	while (pow-- > 0)
		result = result * val;
	return (result);
}

int	ft_convert(int dc, char *base, char *str)
{
	int	str_len;
	int	result;
	int	power;
	int	sign;
	int	incr;

	sign = 1;
	result = 0;
	incr = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	str_len = get_ind_len(str, 0, 0);
	dc = str_valid(str, base);
	while (incr < dc)
	{
		power = get_power(get_ind_len(base, 0, 0), dc - incr - 1);
		result += get_ind_len(base, str[incr], 1) * power;
		incr++;
	}
	return (sign * result);
}

int	ft_atoi_base(char *str, char *b)
{
	int	incr;
	int	si;

	si = 0;
	incr = 0;
	while (b[incr])
	{
		si = incr + 1;
		while (b[si])
		{
			if (b[incr] == b[si] || (b[si] >= '\t' && b[si] <= '\r'))
				return (0);
			if (b[si] == '+' || b[si] == '-' || b[si] == ' ')
				return (0);
			si++;
		}
		incr++;
	}
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (get_ind_len(b, 0, 0) <= 1)
		return (0);
	return (ft_convert(0, b, str));
}
