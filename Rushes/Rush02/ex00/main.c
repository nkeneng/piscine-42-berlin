/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:37:02 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/18 02:01:01 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include <stdio.h>

void	free_dict(struct s_Dict *dict, int dic_len)
{
	int	index;

	index = 0;
	while (index < dic_len)
	{
		free(dict[index].word);
		free(dict[index].number);
		index++;
	}
}

void	rush02(char *str, int str_len, int dic_len, char *buffer)
{
	struct s_Dict	*dict; 
	int				index;
	int				print_zero;

	index = 0;
	print_zero = 1;
	dict = malloc(dic_len * sizeof(struct s_Dict));
	if (!dict) 
		return ;
	extract_dic_elements(buffer, dict);
	sort_dict(dict, dic_len);
	if (str_len == 1)
		ft_putstr(dict[char_to_int(str[0])].word);
	else if (str_len == 2)
		tens_handler(str, dict, 1);
	else
	{
		if (str_len % 3 == 0)
			loop_handle3(str, dict, dic_len, print_zero);
		else if ((str_len -2) % 3 == 0)
		{
			if (tens_handler(str, dict, 1))
			{
				index = find_from_digit(str_len - 1, dict, dic_len);
				ft_putstr(dict[index].word);
				print_zero = 0;
			}
			loop_handle3(&str[2], dict, dic_len, print_zero);
		}
		else if ((str_len - 1) % 3 == 0)
		{
			index = char_to_int(str[0]);
			if (index > 0)
			{
				ft_putstr(dict[index].word);
				index = find_from_digit(str_len, dict, dic_len);
				ft_putstr(dict[index].word);
				print_zero = 0;
			}
			loop_handle3(&str[1], dict, dic_len, print_zero);
		}
	}
	free_dict(dict, dic_len);
	free(dict);
}

int	main(int argc, char *argv[])
{
	int		len;
	int		sign;
	char	*buffer;
	int		new_dict;

	sign = 1;
	new_dict = 0;
	if (argc < 2)
	{
		write(1, "submit at least one arg", 23);
		return (-1);
	}
	else
	{
		if (argc >= 3)
		{
			new_dict = 1;
			len = parse_ui(&argv[2], &sign);
		}
		else 
			len = parse_ui(&argv[1], &sign);
	}
	if (sign < 0 || len <= 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (new_dict)
		buffer = read_file(argv[1]);
	else 
		buffer = read_file("numbers.dict");
	if (buffer == NULL)
		return (-1);
	/*if (!(is_valid_dictionary(buffer)))
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}*/
	if (new_dict)
		rush02(argv[2], len, extract_lines(buffer), buffer);
	else
		rush02(argv[1], len, extract_lines(buffer), buffer);
	free(buffer);
	return (0);
}
