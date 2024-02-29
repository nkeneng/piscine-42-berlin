/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:12:04 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/07 19:09:10 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	incr;
	int	ascii_value;

	incr = 0;
	if (str[incr] == '\0')
		return (1);
	while (str[incr] != '\0')
	{
		ascii_value = str[incr];
		if (ascii_value <= 31 || ascii_value >= 127)
			return (0);
		incr++;
	}
	return (1);
}
