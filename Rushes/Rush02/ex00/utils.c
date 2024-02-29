/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:04:42 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/17 23:13:45 by snkeneng         ###   ########.fr       */
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

int	char_to_int(char c)
{
	return (c - '0');
}
