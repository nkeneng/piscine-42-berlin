/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:23:23 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 20:14:44 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	dest_size;
	int	incr;

	dest_size = 0;
	incr = -1;
	while (dest[dest_size])
		dest_size++;
	while (src[++incr])
		dest[dest_size + incr] = src[incr];
	dest[dest_size + incr] = '\0';
	return (dest);
}
