/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:32:31 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/17 23:17:38 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	tens_handler(char *str, struct s_Dict *dict, int p_z)
{
	int	index;

	if (str[0] == '0')
	{
		if (str[1] != '0' || (p_z && str[1] == '0'))
		{
			index = char_to_int(str[1]);
			ft_putstr(dict[index].word);
			return (1);
		}
		return (0);
	}
	if (str[0] == '1')
	{
		index = ft_atoi(str);
		ft_putstr(dict[index].word);
	}
	else if (str[0] != '1')
	{
		index = 20 + (ft_atoi(str) - 20) / 10;
		ft_putstr(dict[index].word);
		index = ft_atoi(str) % 10;
		ft_putstr(dict[index].word);
	}
	return (1);
}

int	hund_handler(char *str, struct s_Dict *dict, int dic_len, int p_z)
{
	int	index;

	index = char_to_int(str[0]);
	if (index > 0)
	{
		ft_putstr(dict[index].word);
		index = find_from_digit(3, dict, dic_len);
		ft_putstr(dict[index].word);
		p_z = 0;
	}
	if (!tens_handler(&str[1], dict, p_z) && index <= 0)
		return (0);
	return (1);
}

void	loop_handle3(char *str, struct s_Dict *dict, int dic_len, int p_z)
{
	int	index;
	int	len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (hund_handler(str, dict, dic_len, p_z))
		{
			if (len > 3)
			{
				index = find_from_digit(len - 2, dict, dic_len);
				ft_putstr(dict[index].word);
			}
		}
		p_z = 0;
		len -= 3;
		str += 3;
	}
}
