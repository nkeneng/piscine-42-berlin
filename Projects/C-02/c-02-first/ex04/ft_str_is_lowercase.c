/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:58:27 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 19:05:43 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr] != '\0')
	{
		if (!(str[incr] >= 'a' && str[incr] <= 'z'))
			return (0);
		incr++;
	}
	return (1);
}
