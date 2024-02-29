/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:35:34 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 18:35:55 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	incr;

	incr = 0;
	while (src[incr] != '\0' && incr < size - 1)
	{
		dest[incr] = src[incr];
		incr++;
	}
	dest[incr] = '\0';
	while (src[incr] != '\0')
		incr++;
	return (incr);
}
