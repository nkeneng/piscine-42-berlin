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

/*int	get_power(int power_number)
{
	int	result;

	result = 1;
	while (power_number > 0)
	{
		result *= 10;
		power_number--;
	}
	return (result);
}
*/

int	handle_digit_addition(int digit_counter, char *str, int sign)
{
	int	result;
	int	incr;

	result = 0;
	incr = 0;
	while (digit_counter > 0)
	{
		if (str[incr] >= '0' && str[incr] <= '9')
		{
			result = result * 10 + (str[incr] - 48);
			digit_counter--;
		}
		incr++;
	}
	if (sign < 0)
		result *= -1;
	return (result);
}

int	handle_str_loop(char *str, int digit_counter, int *sign)
{
	int	incr;

	incr = 0;
	while (str[incr])
	{
		if (str[incr] >= '0' && str[incr] <= '9')
			digit_counter++;
		else if (str[incr] == '-' && digit_counter == 0)
			*sign *= -1;
		else if (str[incr] == '+' && digit_counter == 0)
			*sign = *sign;
		else if (str[incr] != ' ' || digit_counter != 0)
			break ;
		incr++;
	}
	return (digit_counter);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	digit_counter;

	sign = 1;
	digit_counter = 0;
	digit_counter = handle_str_loop(str, digit_counter, &sign);
	return (handle_digit_addition(digit_counter, str, sign));
}
