/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:20:13 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/18 19:30:45 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	modulo2(struct s_Dict *dict, char *str, int str_len, int dic_len)
{
	int	index;
	int	print_zero;

	index = 0;
	print_zero = 1;
	if (tens_handler(str, dict, 1))
	{
		index = find_from_digit(str_len - 1, dict, dic_len);
		ft_putstr(dict[index].word);
		print_zero = 0;
	}
	loop_handle3(&str[2], dict, dic_len, print_zero);
}

void	modulo3(struct s_Dict *dict, char *str, int str_len, int dic_len)
{
	int	index;
	int	print_zero;

	index = char_to_int(str[0]);
	print_zero = 1;
	if (index > 0)
	{
		ft_putstr(dict[index].word);
		index = find_from_digit(str_len, dict, dic_len);
		ft_putstr(dict[index].word);
		print_zero = 0;
	}
	loop_handle3(&str[1], dict, dic_len, print_zero);
}

void	handle_rush(struct s_Dict *dict, int dic_len, char *str, int str_len)
{
	int	print_zero;

	print_zero = 1;
	if (str_len == 1)
		ft_putstr(dict[char_to_int(str[0])].word);
	else if (str_len == 2)
		tens_handler(str, dict, 1);
	else
	{
		if (str_len % 3 == 0)
			loop_handle3(str, dict, dic_len, print_zero);
		else if ((str_len -2) % 3 == 0)
			modulo2(dict, str, str_len, dic_len);
		else if ((str_len - 1) % 3 == 0)
			modulo3(dict, str, str_len, dic_len);
	}
}
