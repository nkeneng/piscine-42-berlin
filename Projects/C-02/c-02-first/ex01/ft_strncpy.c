/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:08:52 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 19:03:06 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int b)
{
	unsigned int	incr;

	incr = 0;
	while (src[incr] != '\0' && incr < b)
	{
		dest[incr] = src[incr];
		incr++;
	}
	while (incr < b)
	{
		dest[incr] = '\0';
		incr++;
	}
	return (dest);
}
