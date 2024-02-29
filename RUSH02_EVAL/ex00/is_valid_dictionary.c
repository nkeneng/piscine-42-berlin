/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_dictionary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcombe <dcombe@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:14:54 by dcombe            #+#    #+#             */
/*   Updated: 2024/02/18 20:02:10 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_dictionary(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[0] >= '0' && str[0] <= '9'))
			return (0);
		else if (str[i] == '\n' && (str[i + 1] < '0' && str[i + 1] > '9'))
			return (0);
		else if (str[i] == ':' && (!(str[i + 1] >= ' ' && str[i + 1] <= '~')))
			return (0);
		else 
			i++;
	}
	return (1);
}
