/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:06:17 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 19:03:57 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr] != '\0')
	{
		if (!(str[incr] >= '0' && str[incr] <= '9'))
		{
			return (0);
		}
		incr++;
	}
	return (1);
}
