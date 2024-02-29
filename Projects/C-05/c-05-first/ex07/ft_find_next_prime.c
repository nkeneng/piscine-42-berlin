/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:12:50 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/19 17:18:18 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	tmp;

	if (nb == 2 || nb == 3)
		return (1);
	if (nb <= 1 || nb % 2 == 0)
		return (0);
	tmp = 3;
	while (tmp <= nb / tmp)
	{
		if (nb % tmp == 0)
			return (0);
		tmp += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	tmp;

	tmp = nb;
	while (ft_is_prime(tmp) == 0)
		tmp++;
	return (tmp);
}
