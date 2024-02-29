/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:50:36 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 14:52:19 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	incr;

	incr = 0;
	while (s1[incr] != '\0' || s2[incr] != '\0')
	{
		if (s1[incr] > s2[incr])
			return (s1[incr] - s2[incr]);
		else if (s1[incr] < s2[incr])
			return (s1[incr] - s2[incr]);
		incr++;
	}
	return (0);
}
