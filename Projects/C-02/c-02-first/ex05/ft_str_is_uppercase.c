/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:02:51 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 19:08:23 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr] != '\0')
	{
		if (!((str[incr] >= 'A' && str[incr] <= 'Z')))
			return (0);
		incr++;
	}
	return (1);
}
