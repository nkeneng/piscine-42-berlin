/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:29:59 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/19 13:36:27 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	tmp;

	if (nb == 1)
		return (1);
	tmp = 1;
	while (tmp <= nb / tmp)
	{
		if (tmp * tmp == nb)
			return (tmp);
		tmp++;
	}
	return (0);
}
