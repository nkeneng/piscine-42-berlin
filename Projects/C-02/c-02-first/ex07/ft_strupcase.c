/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:03:11 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 19:10:25 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr] != '\0')
	{
		if ((str[incr] >= 'a' && str[incr] <= 'z'))
			str[incr] -= 32;
		incr++;
	}
	return (str);
}
