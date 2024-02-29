/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:37:02 by snkeneng          #+#    #+#             */
/*   Updated: 2024/02/18 20:15:50 by snkeneng         ###   ########.fr       */
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

	dict = malloc(dic_len * sizeof(struct s_Dict));
	if (!dict) 
		return ;
	extract_dic_elements(buffer, dict);
	sort_dict(dict, dic_len);
	if (has_duplicates(dict, dic_len))
		return ;
	handle_rush(dict, dic_len, str, str_len);
	free_dict(dict, dic_len);
	free(dict);
}

int	ft_start2(char **argv, int new_dict, int len)
{
	char	*buffer;

	if (new_dict)
		buffer = read_file(argv[1]);
	else 
		buffer = read_file("numbers.dict");
	if (buffer == NULL)
		return (-1);
	if (!(is_valid_dictionary(buffer)))
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (new_dict)
		rush02(argv[2], len, extract_lines(buffer), buffer);
	else
		rush02(argv[1], len, extract_lines(buffer), buffer);
	free(buffer);
	return (0);
}

int	ft_start(char **argv, int argc)
{
	int		len;
	int		sign;
	int		new_dict;

	new_dict = 0;
	if (argc >= 3)
	{
		new_dict = 1;
		len = parse_ui(&argv[2], &sign);
	}
	else 
		len = parse_ui(&argv[1], &sign);
	if (sign < 0 || len <= 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (ft_start2(argv, new_dict, len));
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(1, "submit at least one arg", 23);
		return (-1);
	}
	else
		return (ft_start(argv, argc));
}
