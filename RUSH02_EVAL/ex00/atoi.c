/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:46:31 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/18 01:57:36 by snkeneng         ###   ########.fr       */
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

int	parse_ui(char **str, int *sign)
{
	int	incr;

	*sign = 1;
	incr = 0;
	while (**str == 32 || (**str >= 9 && **str <= 13))
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign *= -1;
		(*str)++;
	}
	while ((*str)[0] == '0' && (*str)[1] != '\0')
	{
		if ((*str)[1] == '0')
			(*str)++;
		else
			break ;
	}
	while ((*str)[incr] >= '0' && (*str)[incr] <= '9')
		incr++;
	(*str)[incr] = '\0';
	return (ft_strlen(*str));
}

int	ft_atoi(char *str)
{
	int	result;
	int	incr;

	result = 0;
	incr = 0;
	while (incr < 2 && *str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		incr++;
		str++;
	}
	return (result);
}

long	ft_atol(char *str)
{
	long	result;
	int		incr;

	result = 0;
	incr = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		incr++;
		str++;
	}
	return (result);
}
