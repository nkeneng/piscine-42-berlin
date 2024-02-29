/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:09:51 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 18:34:34 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	incr;

	incr = 0;
	while (incr < n && (s1[incr] != '\0' || s2[incr] != '\0'))
	{
		if (s1[incr] != s2[incr])
			return (s1[incr] - s2[incr]);
		incr++;
	}
	return (0);
}
