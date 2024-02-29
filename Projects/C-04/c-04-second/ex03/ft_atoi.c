/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:32:26 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/14 14:55:41 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	handle_digit_addition(char *str, int sign)
{
	int	result;
	int	incr;

	result = 0;
	incr = 0;
	while (str[incr] >= '0' && str[incr] <= '9')
	{
		result = result * 10 + (str[incr] - 48);
		incr++;
	}
	return (sign * result);
}

int	handle_str_sign(char *str, int *sign)
{
	int	incr;

	incr = 0;
	while (str[incr] == '-' || str[incr] == '+')
	{
		if (str[incr] == '-')
			*sign *= -1;
		incr++;
	}
	return (incr);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	incr;
	int	digit_counter;

	sign = 1;
	digit_counter = 0;
	incr = 0;
	while (str[incr] == ' ' || (str[incr] >= '\t' && str[incr] <= '\r'))
		incr++;
	str += incr;
	str += handle_str_sign(str, &sign);
	return (handle_digit_addition(str, sign));
}
