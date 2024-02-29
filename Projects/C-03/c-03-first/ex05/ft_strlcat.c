/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:17:05 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/12 12:57:34 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				dest_size;
	unsigned int	incr;

	dest_size = 0;
	incr = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[incr] && dest_size + incr < size - 1)
	{
		dest[dest_size + incr] = src[incr];
		incr++;
	}
	dest[dest_size + incr] = '\0';
	return (dest_size + incr);
}
