/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:24:35 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 19:11:05 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	incr;

	incr = 0;
	while (str[incr] != '\0')
	{
		if ((str[incr] >= 'A' && str[incr] <= 'Z'))
			str[incr] += 32;
		incr++;
	}
	return (str);
}
