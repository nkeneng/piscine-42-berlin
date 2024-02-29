/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:52:11 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/08 12:56:17 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_size;
	unsigned int	incr;

	dest_size = 0;
	incr = -1;
	while (dest[dest_size])
		dest_size++;
	while (src[++incr] && incr < nb)
		dest[dest_size + incr] = src[incr];
	dest[dest_size + incr] = '\0';
	return (dest);
}
