/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:34:04 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/05 16:07:48 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	incr;

	incr = 0;
	while (src[incr] != '\0')
	{
		dest[incr] = src[incr];
		incr++;
	}
	dest[incr] = src[incr];
	return (dest);
}
